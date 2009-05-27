/***************************************************************************

Namco 50XX

This custom chip is a Fujitsu MB8842 MCU programmed to act as a protection
device. It keeps track of the players scores, and checks if a high score has
been obtained or bonus lives should be awarded. The main CPU has a range of
commands to increment/decrement the score by various fixed amounts.

The device is used to its full potential only by Bosconian; Xevious uses it
too, but only to do a protection check on startup.

CMD = command from main CPU
ANS = answer to main CPU

The chip reads/writes the I/O ports when the /IRQ is pulled down. Pin 21
determines whether a read or write should happen (1=R, 0=W).

      +------+
 EXTAL|1   28|Vcc
  XTAL|2   27|CMD7
/RESET|3   26|CMD6
  ANS0|4   25|CMD5
  ANS1|5   24|CMD4
  ANS2|6   23|/IRQ
  ANS3|7   22|n.c.
  ANS4|8   21|R/W
  ANS5|9   20|n.c.
  ANS6|10  19|n.c.
  ANS7|11  18|n.c.
  CMD0|12  17|n.c.
  CMD1|13  16|CMD3
   GND|14  15|CMD2
      +------+



Commands:

0x = nop

1x = reset scores

2x = set first bonus score (followed by 3 bytes)

3x = set interval bonus score (followed by 3 bytes)

4x = ?

5x = set high score (followed by 3 bytes)

60 = switch to player 1
68 = switch to player 2

70 = switch to increment score
7x = switch to decrement score

score increments/decrements:

80 =    5
81 =   10
82 =   15
83 =   20
84 =   25
85 =   30
86 =   40
87 =   50
88 =   60
89 =   70
8A =   80
8B =   90
8C =  100
8D =  200
8E =  300
8F =  500

9x same as 8x but *10
Ax same as 8x but *100

B0h =   10
B1h =   20
B2h =   30
B3h =   40
B4h =   50
B5h =   60
B6h =   80
B7h =  100
B8h =  120
B9h =  140
BAh =  160
BBh =  180
BCh =  200
BDh =  400
BEh =  600
BFh = 1000

Cx same as Bx but *10
Dx same as Bx but *100

E0 =   15
E1 =   30
E2 =   45
E3 =   60
E4 =   75
E5 =   90
E6 =  120
E7 =  150
E8 =  180
E9 =  210
EA =  240
EB =  270
EC =  300
ED =  600
EE =  900
EF = 1500

Fx same as Ex but *10


When reading, the score for the currently selected player is returned. The first
byte also contains flags.

Byte 0: BCD Score (fs------) and flags
Byte 1: BCD Score (--ss----)
Byte 2: BCD Score (----ss--)
Byte 3: BCD Score (------ss)

Flags: 80=high score, 40=first bonus, 20=interval bonus, 10=?

***************************************************************************/

#include "driver.h"
#include "namco50.h"
#include "cpu/mb88xx/mb88xx.h"


typedef struct _namco_50xx_state namco_50xx_state;
struct _namco_50xx_state
{
	const device_config *	cpu;
	UINT8					latched_cmd;
	UINT8					latched_rw;
	UINT8					portO;
};

INLINE namco_50xx_state *get_safe_token(const device_config *device)
{
	assert(device != NULL);
	assert(device->token != NULL);
	assert(device->type == NAMCO_50XX);

	return (namco_50xx_state *)device->token;
}



static TIMER_CALLBACK( namco_50xx_latch_callback )
{
	namco_50xx_state *state = get_safe_token((const device_config *)ptr);
	state->latched_cmd = param;
	state->latched_rw = 1;
}


static TIMER_CALLBACK( namco_50xx_readrequest_callback )
{
	namco_50xx_state *state = get_safe_token((const device_config *)ptr);
	state->latched_rw = 0;
}


static READ8_HANDLER( namco_50xx_K_r )
{
	namco_50xx_state *state = get_safe_token(space->cpu->owner);
	return state->latched_cmd >> 4;
}

static READ8_HANDLER( namco_50xx_R0_r )
{
	namco_50xx_state *state = get_safe_token(space->cpu->owner);
	return state->latched_cmd & 0x0f;
}

static READ8_HANDLER( namco_50xx_R2_r )
{
	namco_50xx_state *state = get_safe_token(space->cpu->owner);
	return state->latched_rw & 1;
}



static WRITE8_HANDLER( namco_50xx_O_w )
{
	namco_50xx_state *state = get_safe_token(space->cpu->owner);
	UINT8 out = (data & 0x0f);
	if (data & 0x10)
		state->portO = (state->portO & 0x0f) | (out << 4);
	else
		state->portO = (state->portO & 0xf0) | (out);
}




static TIMER_CALLBACK( namco_50xx_irq_clear )
{
	namco_50xx_state *state = get_safe_token((const device_config *)ptr);
	cpu_set_input_line(state->cpu, 0, CLEAR_LINE);
}

static void namco_50xx_irq_set(const device_config *device)
{
	namco_50xx_state *state = get_safe_token(device);

	cpu_set_input_line(state->cpu, 0, ASSERT_LINE);

	// The execution time of one instruction is ~4us, so we must make sure to
	// give the cpu time to poll the /IRQ input before we clear it.
	// The input clock to the 06XX interface chip is 64H, that is
	// 18432000/6/64 = 48kHz, so it makes sense for the irq line to be
	// asserted for one clock cycle ~= 21us.
	timer_set(device->machine, ATTOTIME_IN_USEC(21), (void *)device, 0, namco_50xx_irq_clear);
}

WRITE8_DEVICE_HANDLER( namco_50xx_write )
{
	timer_call_after_resynch(device->machine, (void *)device, data, namco_50xx_latch_callback);

	namco_50xx_irq_set(device);
}


void namco_50xx_read_request(const device_config *device)
{
	timer_call_after_resynch(device->machine, (void *)device, 0, namco_50xx_readrequest_callback);

	namco_50xx_irq_set(device);
}


READ8_DEVICE_HANDLER( namco_50xx_read )
{
	namco_50xx_state *state = get_safe_token(device);
	UINT8 res = state->portO;

	namco_50xx_read_request(device);

	return res;
}


/***************************************************************************
    DEVICE INTERFACE
***************************************************************************/

ADDRESS_MAP_START( namco_50xx_map_io, ADDRESS_SPACE_IO, 8 )
	AM_RANGE(MB88_PORTK,  MB88_PORTK)  AM_READ(namco_50xx_K_r)
	AM_RANGE(MB88_PORTO,  MB88_PORTO)  AM_WRITE(namco_50xx_O_w)
	AM_RANGE(MB88_PORTR0, MB88_PORTR0) AM_READ(namco_50xx_R0_r)
	AM_RANGE(MB88_PORTR2, MB88_PORTR2) AM_READ(namco_50xx_R2_r)
ADDRESS_MAP_END


static MACHINE_DRIVER_START( namco_50xx )
	MDRV_CPU_ADD("mcu", MB8842, DERIVED_CLOCK(1,1))		/* parent clock, internally divided by 6 */
	MDRV_CPU_IO_MAP(namco_50xx_map_io)
MACHINE_DRIVER_END


ROM_START( namco_50xx )
	ROM_REGION( 0x800, "mcu", ROMREGION_LOADBYNAME )
	ROM_LOAD( "50xx.bin",     0x0000, 0x0800, CRC(a0acbaf7) SHA1(f03c79451e73b3a93c1591cdb27fedc9f130508d) )
ROM_END


/*-------------------------------------------------
    device start callback
-------------------------------------------------*/

static DEVICE_START( namco_50xx )
{
	namco_50xx_state *state = get_safe_token(device);
	astring *tempstring = astring_alloc();

	/* find our CPU */
	state->cpu = cputag_get_cpu(device->machine, device_build_tag(tempstring, device, "mcu"));
	assert(state->cpu != NULL);
	astring_free(tempstring);
}


/*-------------------------------------------------
    device reset callback
-------------------------------------------------*/

static DEVICE_RESET( namco_50xx )
{
//	namco_50xx_state *state = get_safe_token(device);
}


/*-------------------------------------------------
    device get info callback
-------------------------------------------------*/

DEVICE_GET_INFO( namco_50xx )
{
	switch (state)
	{
		/* --- the following bits of info are returned as 64-bit signed integers --- */
		case DEVINFO_INT_TOKEN_BYTES:			info->i = sizeof(namco_50xx_state);				break;
		case DEVINFO_INT_CLASS:					info->i = DEVICE_CLASS_PERIPHERAL;				break;

		/* --- the following bits of info are returned as pointers --- */
		case DEVINFO_PTR_ROM_REGION:			info->romregion = ROM_NAME(namco_50xx);			break;
		case DEVINFO_PTR_MACHINE_CONFIG:		info->machine_config = MACHINE_DRIVER_NAME(namco_50xx); break;

		/* --- the following bits of info are returned as pointers to data or functions --- */
		case DEVINFO_FCT_START:					info->start = DEVICE_START_NAME(namco_50xx); 	break;
		case DEVINFO_FCT_RESET:					info->reset = DEVICE_RESET_NAME(namco_50xx); 	break;

		/* --- the following bits of info are returned as NULL-terminated strings --- */
		case DEVINFO_STR_NAME:					strcpy(info->s, "Namco 50xx");					break;
		case DEVINFO_STR_FAMILY:				strcpy(info->s, "Namco I/O");					break;
		case DEVINFO_STR_VERSION:				strcpy(info->s, "1.0");							break;
		case DEVINFO_STR_SOURCE_FILE:			strcpy(info->s, __FILE__);						break;
		case DEVINFO_STR_CREDITS:				strcpy(info->s, "Copyright Nicola Salmoria and the MAME Team"); break;
	}
}
