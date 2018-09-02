// license:BSD-3-Clause
// copyright-holders:Ernesto Corvi
/***************************************************************************

The Simpsons (c) 1991 Konami Co. Ltd

Preliminary driver by:
Ernesto Corvi
someone@secureshell.com


****************************************************************************

The Simpsons
Konami 1991

PCB Layout
----------

GX072 PWB352346B
|--------------------------------------------------------|
| MB3722   072D04.1D  072D05.1F           8464           |
|VOL VOL   YM2151   |------|            |------|072B08.3N|
|          YM3012   |053260| 3.579545MHz|053246|         |
|CN3                |      |            |      |         |
|                   |------|            |      |         |
|                   Z80     072E03.6G   |      |         |
|                                       |------|         |
|                           8416                         |
|                           2018        |------|         |
|  052535                   2018        |053247|072B09.8N|
|  052535                               |      |         |
|J 052535                               |      |         |
|A                                      |      |         |
|M 051550                               |------|         |
|M                                      |------|         |
|A     053994  053995   8464            |053251|         |
|                                       |      |072B10.12N
|   ER5911.12C                          |------|         |
|      072M13.13C             |------|  |------|         |
|005273(X10)      |------|    |052109|  |051962|         |
|      072L12.15C |053248|    |      |  |      |         |
|TEST_SW          |      |    |      |  |      |         |
|      072G02.16C |------|    |------|  |------|072B11.16L
|CN6                         8464 072B06.16H             |
|CN7   072G01.17C      24MHz 8464 072B07.18H             |
|--------------------------------------------------------|
Notes:
      ER5911 - EEPROM (128 bytes)
      8464   - Fujitsu MB8464 8kx8 SRAM (DIP28)
      8416   - Fujitsu MB8416 2kx8 SRAM (DIP24)
      2018   - Motorola MCM2018 2kx8 SRAM (DIP24)
      MB3722 - Audio Power AMP
      Z80    - Clock 3.579545MHz
      YM2151 - Clock 3.579545MHz
      YM3012 - Clock 1.7897725MHz [3.579545/2]
      CN6/7  - 15 pin connector for player 3 and player 4 controls
      CN3    - 4 pin connector for stereo sound output for left & right speaker
               (left speaker also outputs via JAMMA connector)

      Custom Chips
      ------------
      053248 - CPU (QFP80). Clock input 12.000MHz [24/2]. Clock output 3.000MHz [24/8]
      053260 - Sound chip (QFP80). Clock input 3.579545MHz. Clock output 1.7897725 [3.579545/2] for YM3012
      053246 \
      053247 / Sprite generators (QFP120)
      052109 \
      051962 / Tilemap Generators (QFP120)
      053251 - Priority encoder (QFP100)
      052535 - RGB DAC (ceramic encased SIP9)
      051550 - EMI filter for credit/coin counter (ceramic encased SIP23)
      005273 - Resistor array for player 3 & player 4 controls (ceramic encased SIP10)
      053994 \
      053995 / PALs (MMI PAL16L8, DIP20)

      ROMs
      ----
      072D04 -  256kx8 DIP40 MaskROM (Sound Samples)
      072D05 -  1Mx8 DIP40 MaskROM (Sound Samples)
      072E03 -  32kx8 MaskROM (Z80 Sound Program)
      072B08 \
      072B09  |
      072B10  | 512kx16 DIP40 MaskROM (Sprites)
      072B11 /
      072B06 \
      072B07 /  256kx16 DIP40 MaskROM (Tiles)
      072M13 \
      072L12  |
      072G02  | 128kx8 DIP32 MaskROM (Main Program)
      072G01 /

      Sync Measurements
      -----------------
      VSync - 59.1856Hz
      HSync - 15.1566kHz

***************************************************************************/

#include "emu.h"
#include "includes/simpsons.h"
#include "includes/konamipt.h"

#include "cpu/m6809/konami.h" /* for the callback and the firq irq definition */
#include "cpu/z80/z80.h"
#include "machine/eepromser.h"
#include "machine/watchdog.h"
#include "sound/ym2151.h"
#include "sound/k053260.h"
#include "emupal.h"
#include "speaker.h"


/***************************************************************************

  Memory Maps

***************************************************************************/

void simpsons_state::main_map(address_map &map)
{
	map(0x0000, 0x1fff).rw(m_k052109, FUNC(k052109_device::read), FUNC(k052109_device::write));
	map(0x0000, 0x0fff).m(m_bank0000, FUNC(address_map_bank_device::amap8));
	map(0x2000, 0x3fff).m(m_bank2000, FUNC(address_map_bank_device::amap8));
	map(0x1f80, 0x1f80).portr("COIN");
	map(0x1f81, 0x1f81).portr("TEST");
	map(0x1f90, 0x1f90).portr("P1");
	map(0x1f91, 0x1f91).portr("P2");
	map(0x1f92, 0x1f92).portr("P3");
	map(0x1f93, 0x1f93).portr("P4");
	map(0x1fa0, 0x1fa7).w(m_k053246, FUNC(k053247_device::k053246_w));
	map(0x1fb0, 0x1fbf).w(m_k053251, FUNC(k053251_device::write));
	map(0x1fc0, 0x1fc0).w(FUNC(simpsons_state::simpsons_coin_counter_w));
	map(0x1fc2, 0x1fc2).w(FUNC(simpsons_state::simpsons_eeprom_w));
	map(0x1fc4, 0x1fc4).r(FUNC(simpsons_state::simpsons_sound_interrupt_r));
	map(0x1fc6, 0x1fc7).rw("k053260", FUNC(k053260_device::main_read), FUNC(k053260_device::main_write));
	map(0x1fc8, 0x1fc9).r(m_k053246, FUNC(k053247_device::k053246_r));
	map(0x1fca, 0x1fca).r("watchdog", FUNC(watchdog_timer_device::reset_r));
	map(0x4000, 0x5fff).ram();
	map(0x6000, 0x7fff).bankr("bank1");
	map(0x8000, 0xffff).rom().region("maincpu", 0x78000);
}

void simpsons_state::bank0000_map(address_map &map)
{
	map(0x0000, 0x0fff).rw(m_k052109, FUNC(k052109_device::read), FUNC(k052109_device::write));
	map(0x1000, 0x1fff).ram().w("palette", FUNC(palette_device::write8)).share("palette");
}

void simpsons_state::bank2000_map(address_map &map)
{
	map(0x0000, 0x1fff).rw(FUNC(simpsons_state::simpsons_k052109_r), FUNC(simpsons_state::simpsons_k052109_w));
	map(0x2000, 0x2fff).rw(FUNC(simpsons_state::simpsons_k053247_r), FUNC(simpsons_state::simpsons_k053247_w));
	map(0x3000, 0x3fff).ram();
}

WRITE8_MEMBER(simpsons_state::z80_bankswitch_w)
{
	membank("bank2")->set_entry(data & 7);
}

#if 0
void simpsons_state::sound_nmi_callback( int param )
{
	m_audiocpu->set_input_line(INPUT_LINE_NMI, (m_nmi_enabled) ? CLEAR_LINE : ASSERT_LINE );
	m_nmi_enabled = 0;
}
#endif


void simpsons_state::device_timer(emu_timer &timer, device_timer_id id, int param, void *ptr)
{
	switch (id)
	{
	case TIMER_NMI:
		m_audiocpu->set_input_line(INPUT_LINE_NMI, ASSERT_LINE);
		break;
	case TIMER_DMAEND:
		if (m_firq_enabled)
			m_maincpu->set_input_line(KONAMI_FIRQ_LINE, HOLD_LINE);
		break;
	default:
		assert_always(false, "Unknown id in simpsons_state::device_timer");
	}
}


WRITE8_MEMBER(simpsons_state::z80_arm_nmi_w)
{
	m_audiocpu->set_input_line(INPUT_LINE_NMI, CLEAR_LINE);
	timer_set(attotime::from_usec(25), TIMER_NMI);  /* kludge until the K053260 is emulated correctly */
}

void simpsons_state::z80_map(address_map &map)
{
	map(0x0000, 0x7fff).rom();
	map(0x8000, 0xbfff).bankr("bank2");
	map(0xf000, 0xf7ff).ram();
	map(0xf800, 0xf801).rw("ymsnd", FUNC(ym2151_device::read), FUNC(ym2151_device::write));
	map(0xfa00, 0xfa00).w(FUNC(simpsons_state::z80_arm_nmi_w));
	map(0xfc00, 0xfc2f).rw("k053260", FUNC(k053260_device::read), FUNC(k053260_device::write));
	map(0xfe00, 0xfe00).w(FUNC(simpsons_state::z80_bankswitch_w));
}

/***************************************************************************

    Input Ports

***************************************************************************/

static INPUT_PORTS_START( simpsons )
	PORT_START("P1")
	KONAMI8_B12_START(1)

	PORT_START("P2")
	KONAMI8_B12_START(2)

	PORT_START("P3")
	KONAMI8_B12_START(3)

	PORT_START("P4")
	KONAMI8_B12_START(4)

	PORT_START("COIN")
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_COIN3 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_COIN4 )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_UNKNOWN ) //SERVICE1 Unused
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN ) //SERVICE2 Unused
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) //SERVICE3 Unused
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN ) //SERVICE4 Unused

	PORT_START("TEST")
	PORT_SERVICE_NO_TOGGLE( 0x01, IP_ACTIVE_LOW )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, do_read)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, ready_read)
	PORT_BIT( 0xce, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START( "EEPROMOUT" )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, cs_write)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, clk_write)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, di_write)
INPUT_PORTS_END

static INPUT_PORTS_START( simpsn2p )
	PORT_START("P1")
	KONAMI8_B12_START(1)

	PORT_START("P2")
	KONAMI8_B12_START(2)

	PORT_START("P3")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("P4")
	PORT_BIT( 0xff, IP_ACTIVE_LOW, IPT_UNUSED )

	PORT_START("COIN") /* IN4 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_COIN1 )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN ) //COIN3 Unused
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN ) //COIN4 Unused
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNKNOWN ) //SERVICE2 Unused
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_UNKNOWN ) //SERVICE3 Unused
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNKNOWN ) //SERVICE4 Unused

	PORT_START("TEST")
	PORT_SERVICE_NO_TOGGLE( 0x01, IP_ACTIVE_LOW )
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, do_read)
	PORT_BIT( 0x20, IP_ACTIVE_HIGH, IPT_CUSTOM ) PORT_READ_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, ready_read)
	PORT_BIT( 0xce, IP_ACTIVE_LOW, IPT_UNKNOWN )

	PORT_START( "EEPROMOUT" )
	PORT_BIT( 0x08, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, cs_write)
	PORT_BIT( 0x10, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, clk_write)
	PORT_BIT( 0x80, IP_ACTIVE_HIGH, IPT_OUTPUT ) PORT_WRITE_LINE_DEVICE_MEMBER("eeprom", eeprom_serial_er5911_device, di_write)
INPUT_PORTS_END



/***************************************************************************

    Machine Driver

***************************************************************************/

void simpsons_state::simpsons_objdma(  )
{
	int counter, num_inactive;
	uint16_t *src, *dst;

	m_k053246->k053247_get_ram(&dst);

	src = m_spriteram.get();
	num_inactive = counter = 256;

	do {
		if ((*src & 0x8000) && (*src & 0xff))
		{
			memcpy(dst, src, 0x10);
			dst += 8;
			num_inactive--;
		}
		src += 8;
	}
	while (--counter);

	if (num_inactive) do { *dst = 0; dst += 8; } while (--num_inactive);
}

INTERRUPT_GEN_MEMBER(simpsons_state::simpsons_irq)
{
	if (m_k053246->k053246_is_irq_enabled())
	{
		simpsons_objdma();
		// 32+256us delay at 8MHz dotclock; artificially shortened since actual V-blank length is unknown
		timer_set(attotime::from_usec(30), TIMER_DMAEND);
	}

	if (m_k052109->is_irq_enabled())
		device.execute().set_input_line(KONAMI_IRQ_LINE, HOLD_LINE);
}

MACHINE_CONFIG_START(simpsons_state::simpsons)

	/* basic machine hardware */
	MCFG_DEVICE_ADD("maincpu", KONAMI, XTAL(24'000'000)/2/4) /* 053248, the clock input is 12MHz, and internal CPU divider of 4 */
	MCFG_DEVICE_PROGRAM_MAP(main_map)
	MCFG_DEVICE_VBLANK_INT_DRIVER("screen", simpsons_state,  simpsons_irq) /* IRQ triggered by the 052109, FIRQ by the sprite hardware */
	MCFG_KONAMICPU_LINE_CB(WRITE8(*this, simpsons_state, banking_callback))

	MCFG_DEVICE_ADD("audiocpu", Z80, XTAL(3'579'545)) /* verified on pcb */
	MCFG_DEVICE_PROGRAM_MAP(z80_map)   /* NMIs are generated by the 053260 */

	ADDRESS_MAP_BANK(config, "bank0000").set_map(&simpsons_state::bank0000_map).set_options(ENDIANNESS_BIG, 8, 13, 0x1000);
	ADDRESS_MAP_BANK(config, "bank2000").set_map(&simpsons_state::bank2000_map).set_options(ENDIANNESS_BIG, 8, 14, 0x2000);

	EEPROM_ER5911_8BIT(config, "eeprom");

	MCFG_WATCHDOG_ADD("watchdog")

	/* video hardware */
	MCFG_SCREEN_ADD("screen", RASTER)
	MCFG_SCREEN_RAW_PARAMS(XTAL(24'000'000)/3, 528, 112, 400, 256, 16, 240)
//  6MHz dotclock is more realistic, however needs drawing updates. replace when ready
//  MCFG_SCREEN_RAW_PARAMS(XTAL(24'000'000)/4, 396, hbend, hbstart, 256, 16, 240)
	MCFG_SCREEN_VIDEO_ATTRIBUTES(VIDEO_UPDATE_AFTER_VBLANK)
	MCFG_SCREEN_UPDATE_DRIVER(simpsons_state, screen_update_simpsons)
	MCFG_SCREEN_PALETTE("palette")

	MCFG_PALETTE_ADD("palette", 2048)
	MCFG_PALETTE_ENABLE_SHADOWS()
	MCFG_PALETTE_ENABLE_HILIGHTS()
	MCFG_PALETTE_FORMAT(xBBBBBGGGGGRRRRR)

	MCFG_DEVICE_ADD("k052109", K052109, 0)
	MCFG_GFX_PALETTE("palette")
	MCFG_K052109_CB(simpsons_state, tile_callback)

	MCFG_DEVICE_ADD("k053246", K053246, 0)
	MCFG_K053246_CB(simpsons_state, sprite_callback)
	MCFG_K053246_CONFIG("gfx2", NORMAL_PLANE_ORDER, 53, 23)
	MCFG_K053246_PALETTE("palette")

	MCFG_K053251_ADD("k053251")

	/* sound hardware */
	SPEAKER(config, "lspeaker").front_left();
	SPEAKER(config, "rspeaker").front_right();

	MCFG_DEVICE_ADD("ymsnd", YM2151, XTAL(3'579'545)) /* verified on pcb */
	MCFG_SOUND_ROUTE(0, "lspeaker", 1.0)    /* only left channel is connected */
	MCFG_SOUND_ROUTE(0, "rspeaker", 1.0)
	MCFG_SOUND_ROUTE(1, "lspeaker", 0.0)
	MCFG_SOUND_ROUTE(1, "rspeaker", 0.0)

	MCFG_DEVICE_ADD("k053260", K053260, XTAL(3'579'545)) /* verified on pcb */
	MCFG_SOUND_ROUTE(0, "lspeaker", 0.75)
	MCFG_SOUND_ROUTE(1, "rspeaker", 0.75)
MACHINE_CONFIG_END


/***************************************************************************

  Game ROMs

***************************************************************************/

ROM_START( simpsons ) /* World 4 Player */
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-g02.16c", 0x00000, 0x20000, CRC(580ce1d6) SHA1(5b07fb8e8041e1663980aa35d853fdc13b22dac5) )
	ROM_LOAD( "072-g01.17c", 0x20000, 0x20000, CRC(9f843def) SHA1(858432b59101b0577c5cec6ac0c7c20ab0780c9a) )
	ROM_LOAD( "072-j13.13c", 0x40000, 0x20000, CRC(aade2abd) SHA1(10f178d5ed399b4866266e075d91ca3db26798f8) )
	ROM_LOAD( "072-j12.15c", 0x60000, 0x20000, CRC(479e12f2) SHA1(15a6cb12e68b4773a29ab463640a43f8e814de59) )

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-e03.6g", 0x00000, 0x08000, CRC(866b7a35) SHA1(98905764eb4c7d968ccc17618a1f24ee12e33c0e) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )    /* tiles */
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons.12c.nv", 0x0000, 0x080, CRC(ec3f0449) SHA1(da35b98cd10bfabe9df3ede05462fabeb0e01ca9) )
ROM_END

ROM_START( simpsons4pe ) /* World 4 Player, later? (by use of later leters) */
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-g02.16c", 0x00000, 0x20000, CRC(580ce1d6) SHA1(5b07fb8e8041e1663980aa35d853fdc13b22dac5) )
	ROM_LOAD( "072-g01.17c", 0x20000, 0x20000, CRC(9f843def) SHA1(858432b59101b0577c5cec6ac0c7c20ab0780c9a) )
	ROM_LOAD( "072-m13.13c", 0x40000, 0x20000, CRC(f36c9423) SHA1(4a7311ffcb2e6916006c1e79dfc231e7fc570781) )
	ROM_LOAD( "072-l12.15c", 0x60000, 0x20000, CRC(84f9d9ba) SHA1(d52f999b7c8125daea5e9b5754c6e82c17861d1b) )

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-e03.6g", 0x00000, 0x08000, CRC(866b7a35) SHA1(98905764eb4c7d968ccc17618a1f24ee12e33c0e) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )    /* tiles */
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons4pe.12c.nv", 0x0000, 0x080, CRC(ec3f0449) SHA1(da35b98cd10bfabe9df3ede05462fabeb0e01ca9) )
ROM_END

ROM_START( simpsons4pa ) /* Asia 4 Player */
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-v02.16c", 0x00000, 0x20000, CRC(580ce1d6) SHA1(5b07fb8e8041e1663980aa35d853fdc13b22dac5) )
	ROM_LOAD( "072-v01.17c", 0x20000, 0x20000, CRC(effd6c09) SHA1(e5bcdb753bccdd76de18ad6ff7346f74fd02a78f) )
	ROM_LOAD( "072-x13.13c", 0x40000, 0x20000, CRC(3304abb9) SHA1(8f23160077f30d76c0c73e0b3f20996826433566) )
	ROM_LOAD( "072-x12.15c", 0x60000, 0x20000, CRC(fa4fca12) SHA1(3b52a8a52bddfa73d8577315b655eb57ac758326) )

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-e03.6g", 0x00000, 0x08000, CRC(866b7a35) SHA1(98905764eb4c7d968ccc17618a1f24ee12e33c0e) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )    /* tiles */
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons4pa.12c.nv", 0x0000, 0x080, CRC(ec3f0449) SHA1(da35b98cd10bfabe9df3ede05462fabeb0e01ca9) )
ROM_END


ROM_START( simpsons2p ) /* World 2 Player */
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-g02.16c", 0x00000, 0x20000, CRC(580ce1d6) SHA1(5b07fb8e8041e1663980aa35d853fdc13b22dac5) )
	ROM_LOAD( "072-p01.17c", 0x20000, 0x20000, CRC(07ceeaea) SHA1(c18255ae1d578c2d53de80d6323cdf41cbe47b57) )
	ROM_LOAD( "072-013.13c", 0x40000, 0x20000, CRC(8781105a) SHA1(ef2f16f7a56d3715536511c674df4b3aab1be2bd) )
	ROM_LOAD( "072-012.15c", 0x60000, 0x20000, CRC(244f9289) SHA1(eeda7f5c7340cbd1a1cd576af48cd5d1a629914a) )

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-g03.6g", 0x00000, 0x08000, CRC(76c1850c) SHA1(9047c6b26c4e33c74eb7400a807d3d9f206f7bbe) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons2p.12c.nv", 0x0000, 0x080, CRC(fbac4e30) SHA1(d3ff3a392550d9b06400b9292a44bdac7ba5c801) )
ROM_END

ROM_START( simpsons2p2 ) /* World 2 Player, alt */
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-g02.16c", 0x00000, 0x20000, CRC(580ce1d6) SHA1(5b07fb8e8041e1663980aa35d853fdc13b22dac5) )
	ROM_LOAD( "072-p01.17c", 0x20000, 0x20000, CRC(07ceeaea) SHA1(c18255ae1d578c2d53de80d6323cdf41cbe47b57) )
	ROM_LOAD( "072-_13.13c", 0x40000, 0x20000, CRC(54e6df66) SHA1(1b83ae56cf1deb51b04880fa421f06568c938a99) ) /* Unknown revision/region code */
	ROM_LOAD( "072-_12.15c", 0x60000, 0x20000, CRC(96636225) SHA1(5de95606e5c9337f18bc42f4df791cacafa20399) ) /* Unknown revision/region code */

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-g03.6g", 0x00000, 0x08000, CRC(76c1850c) SHA1(9047c6b26c4e33c74eb7400a807d3d9f206f7bbe) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )    /* tiles */
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons2p2.12c.nv", 0x0000, 0x080, CRC(fbac4e30) SHA1(d3ff3a392550d9b06400b9292a44bdac7ba5c801) )
ROM_END

ROM_START( simpsons2p3 ) // no rom labels
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-g02.16c", 0x00000, 0x20000, CRC(580ce1d6) SHA1(5b07fb8e8041e1663980aa35d853fdc13b22dac5) )
	ROM_LOAD( "072-p01.17c", 0x20000, 0x20000, CRC(07ceeaea) SHA1(c18255ae1d578c2d53de80d6323cdf41cbe47b57) )
	ROM_LOAD( "4.13c", 0x40000, 0x20000, CRC(c3040e4f) SHA1(f6b5cbee5d7c6642a11d115bb6d93a7f2821cd8f) ) /* Unknown revision/region code */
	ROM_LOAD( "3.15c", 0x60000, 0x20000, CRC(eb4f5781) SHA1(58a556e9b4b9e4bd0e76ac86ab8e062c3f1e2d31) ) /* Unknown revision/region code */

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-g03.6g", 0x00000, 0x08000, CRC(76c1850c) SHA1(9047c6b26c4e33c74eb7400a807d3d9f206f7bbe) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons2p.12c.nv", 0x0000, 0x080, CRC(fbac4e30) SHA1(d3ff3a392550d9b06400b9292a44bdac7ba5c801) )
ROM_END

ROM_START( simpsons2pa ) /* Asia 2 Player */
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-g02.16c", 0x00000, 0x20000, CRC(580ce1d6) SHA1(5b07fb8e8041e1663980aa35d853fdc13b22dac5) ) /* Same as both world 2p sets */
	ROM_LOAD( "072-p01.17c", 0x20000, 0x20000, CRC(07ceeaea) SHA1(c18255ae1d578c2d53de80d6323cdf41cbe47b57) ) /* Same as both world 2p sets */
	ROM_LOAD( "072-113.13c", 0x40000, 0x20000, CRC(8781105a) SHA1(ef2f16f7a56d3715536511c674df4b3aab1be2bd) ) /* Same as world set simpsn2p */
	ROM_LOAD( "072-112.15c", 0x60000, 0x20000, CRC(3bd69404) SHA1(e055fed7e9bde8315ae2f9b2d35bc05fece6b80b) )

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-e03.6g", 0x00000, 0x08000, CRC(866b7a35) SHA1(98905764eb4c7d968ccc17618a1f24ee12e33c0e) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )    /* tiles */
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons2pa.12c.nv", 0x0000, 0x080, CRC(fbac4e30) SHA1(d3ff3a392550d9b06400b9292a44bdac7ba5c801) )
ROM_END

ROM_START( simpsons2pj ) /* Japan 2 Player */
	ROM_REGION( 0x80000, "maincpu", 0 ) /* code + banked roms */
	ROM_LOAD( "072-s02.16c", 0x00000, 0x20000, CRC(265f7a47) SHA1(d39c19a5e303f822313409343b209947f4c47ae4) )
	ROM_LOAD( "072-t01.17c", 0x20000, 0x20000, CRC(91de5c2d) SHA1(1e18a5585ed821ec7cda69bdcdbfa4e6c71455c6) )
	ROM_LOAD( "072-213.13c", 0x40000, 0x20000, CRC(b326a9ae) SHA1(f222c33f2e8b306f2f0ef6f0da9febbf8219e1a4) )
	ROM_LOAD( "072-212.15c", 0x60000, 0x20000, CRC(584d9d37) SHA1(61b9df4dfb323b7284894e5e1eb9d713ebf64721) )

	ROM_REGION( 0x28000, "audiocpu", 0 ) /* Z80 code + banks */
	ROM_LOAD( "072-g03.6g", 0x00000, 0x08000, CRC(76c1850c) SHA1(9047c6b26c4e33c74eb7400a807d3d9f206f7bbe) )
	ROM_CONTINUE(       0x10000, 0x18000 )

	ROM_REGION( 0x100000, "k052109", 0 )    /* tiles */
	ROM_LOAD32_WORD( "072-b07.18h", 0x000000, 0x080000, CRC(ba1ec910) SHA1(0805ccb641271dea43185dc0365732260db1763d) )
	ROM_LOAD32_WORD( "072-b06.16h", 0x000002, 0x080000, CRC(cf2bbcab) SHA1(47afea47f9bc8cb5eb1c7b7fbafe954b3e749aeb) )

	ROM_REGION( 0x400000, "gfx2", 0 ) /* graphics */
	ROM_LOAD64_WORD( "072-b08.3n",  0x000000, 0x100000, CRC(7de500ad) SHA1(61b76b8f402e3bde1509679aaaa28ef08cafb0ab) ) /* sprites */
	ROM_LOAD64_WORD( "072-b09.8n",  0x000002, 0x100000, CRC(aa085093) SHA1(925239d79bf607021d371263352618876f59c1f8) )
	ROM_LOAD64_WORD( "072-b10.12n", 0x000004, 0x100000, CRC(577dbd53) SHA1(e603e03e3dcba766074561faa92afafa5761953d) )
	ROM_LOAD64_WORD( "072-b11.16l", 0x000006, 0x100000, CRC(55fab05d) SHA1(54db8559d71ed257de9a29c8808654eaea0df9e2) )

	ROM_REGION( 0x140000, "k053260", 0 ) /* samples for the 053260 */
	ROM_LOAD( "072-d05.1f", 0x000000, 0x100000, CRC(1397a73b) SHA1(369422c84cca5472967af54b8351e29fcd69f621) )
	ROM_LOAD( "072-d04.1d", 0x100000, 0x040000, CRC(78778013) SHA1(edbd6d83b0d1a20df39bb160b92395586fa3c32d) )

	ROM_REGION( 0x80, "eeprom", 0 ) // default eeprom to prevent game booting upside down with error
	ROM_LOAD( "simpsons2pj.12c.nv", 0x0000, 0x080, CRC(3550a54e) SHA1(370cd40a12c471b3b6690ecbdde9c7979bc2a652) )
ROM_END



/***************************************************************************

  Game driver(s)

***************************************************************************/

// the region warning, if one exists, is shown after the high-score screen in attract mode
GAME( 1991, simpsons,    0,        simpsons, simpsons, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (4 Players World, set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 1991, simpsons4pe, simpsons, simpsons, simpsons, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (4 Players World, set 2)", MACHINE_SUPPORTS_SAVE )
GAME( 1991, simpsons4pa, simpsons, simpsons, simpsons, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (4 Players Asia)",         MACHINE_SUPPORTS_SAVE )
GAME( 1991, simpsons2p,  simpsons, simpsons, simpsn2p, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (2 Players World, set 1)", MACHINE_SUPPORTS_SAVE )
GAME( 1991, simpsons2p2, simpsons, simpsons, simpsons, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (2 Players World, set 2)", MACHINE_SUPPORTS_SAVE )
GAME( 1991, simpsons2p3, simpsons, simpsons, simpsn2p, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (2 Players World, set 3)", MACHINE_SUPPORTS_SAVE )
GAME( 1991, simpsons2pa, simpsons, simpsons, simpsn2p, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (2 Players Asia)",         MACHINE_SUPPORTS_SAVE )
GAME( 1991, simpsons2pj, simpsons, simpsons, simpsn2p, simpsons_state, empty_init, ROT0, "Konami", "The Simpsons (2 Players Japan)",        MACHINE_SUPPORTS_SAVE )
