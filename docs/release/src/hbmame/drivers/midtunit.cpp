// license:BSD-3-Clause
// copyright-holders:Robbbert
#include "../mame/drivers/midtunit.cpp"

ROM_START( mkturbod )
	ROM_REGION( 0x50000, "adpcm:cpu", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u3_sound_rom.u3", 0x10000, 0x40000, CRC(c615844c) SHA1(5732f9053a5f73b0cc3b0166d7dc4430829d5bc7) )

	ROM_REGION( 0x200000, "adpcm:oki", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u12_sound_rom.u12", 0x00000, 0x40000, CRC(258bd7f9) SHA1(463890b23f17350fb9b8a85897b0777c45bc2d54) )
	ROM_RELOAD(              0x40000, 0x40000 )
	ROM_LOAD( "sl1_mortal_kombat_u13_sound_rom.u13", 0x80000, 0x40000, CRC(7b7ec3b6) SHA1(6eec1b90d4a4855f34a7ebfbf93f3358d5627db4) )
	ROM_RELOAD(              0xc0000, 0x40000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "kombo-rom-uj-12.bin", 0x00000, 0x80000, CRC(7a441f2d) SHA1(3b731bcbd73721ea0cc20157ec5181d25922523c) )
	ROM_LOAD16_BYTE( "kombo-hacked-ug-12.bin", 0x00001, 0x80000, CRC(bfab4bb6) SHA1(fc48b4b1fd4f32d9a597e292a1121916c98968d1) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "mkt-ug14.bin", 0x000000, 0x80000, CRC(9e00834e) SHA1(2b97b63f52ba1dba6af6ae56c223519a52b2ab9d) )
	ROM_LOAD32_BYTE( "mkt-uj14.bin", 0x000001, 0x80000, CRC(f4b0aaa7) SHA1(4cc6ee34c89e3cde325ad24b29511f70ae6a5a72) )
	ROM_LOAD32_BYTE( "mkt-ug19.bin", 0x000002, 0x80000, CRC(2d8c7ba1) SHA1(f891d6eb618dbf3e77f02e0f93da216e20571905) )
	ROM_LOAD32_BYTE( "mkt-uj19.bin", 0x000003, 0x80000, CRC(33b9b7a4) SHA1(e8ceca4c049e1f55d480a03ff793b595bd04d344) )

	ROM_LOAD32_BYTE( "mkt-ug16.bin", 0x200000, 0x80000, CRC(52c9d1e5) SHA1(7b1880fca0a11544782b70365c7dd96381ac48e7) )
	ROM_LOAD32_BYTE( "mkt-uj16.bin", 0x200001, 0x80000, CRC(c94c58cf) SHA1(974d75667eee779497325d5be8df937f15417edf) )
	ROM_LOAD32_BYTE( "mkt-ug20.bin", 0x200002, 0x80000, CRC(2f7e55d3) SHA1(bda6892ee6fcb46959e4d0892bbe7d9fc6072dd3) )
	ROM_LOAD32_BYTE( "mkt-uj20.bin", 0x200003, 0x80000, CRC(eae96df0) SHA1(b40532312ba61e4065abfd733dd0c93eecad48e9) )

	ROM_LOAD32_BYTE( "mkt-ug17.bin", 0x400000, 0x80000, CRC(e34fe253) SHA1(6b010bee795c1770297c9557ded1fe83425857f2) )
	ROM_LOAD32_BYTE( "mkt-uj17.bin", 0x400001, 0x80000, CRC(a56e12f5) SHA1(5db637c4710990cd06bb0069714b19621532e431) )
	ROM_LOAD32_BYTE( "mkt-ug22.bin", 0x400002, 0x80000, CRC(b537bb4e) SHA1(05a447deee2e89b49bdb3ca2161a021d7ec5f11e) )
	ROM_LOAD32_BYTE( "mkt-uj22.bin", 0x400003, 0x80000, CRC(5e12523b) SHA1(468f93ef9bb6addb45c1c939d24b6511f255426a) )
ROM_END

ROM_START( mktturboen )
	ROM_REGION( 0x50000, "adpcm:cpu", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u3_sound_rom.u3", 0x10000, 0x40000, CRC(c615844c) SHA1(5732f9053a5f73b0cc3b0166d7dc4430829d5bc7) )

	ROM_REGION( 0x100000, "adpcm:oki", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u12_sound_rom.u12", 0x00000, 0x40000, CRC(258bd7f9) SHA1(463890b23f17350fb9b8a85897b0777c45bc2d54) )
	ROM_RELOAD(              0x40000, 0x40000 )
	ROM_LOAD( "sl1_mortal_kombat_u13_sound_rom.u13", 0x80000, 0x40000, CRC(7b7ec3b6) SHA1(6eec1b90d4a4855f34a7ebfbf93f3358d5627db4) )
	ROM_RELOAD(              0xc0000, 0x40000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "kombo-romen-uj-12.bin", 0x00000, 0x80000, CRC(53069455) SHA1(f86da6036844b3e996fa9b3769e4f9979a920b28) )
	ROM_LOAD16_BYTE( "kombo-rom-ug-12.bin", 0x00001, 0x80000, CRC(45bed5a1) SHA1(dba2c21878925afdcaf61520c18ebefd5e9617db) )
	ROM_FILL(0xF7914, 1, 0x60)
	ROM_FILL(0xF7915, 1, 0x09)

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "mkt-ug14.bin", 0x000000, 0x80000, CRC(9e00834e) SHA1(2b97b63f52ba1dba6af6ae56c223519a52b2ab9d) )
	ROM_LOAD32_BYTE( "mkt-uj14.bin", 0x000001, 0x80000, CRC(f4b0aaa7) SHA1(4cc6ee34c89e3cde325ad24b29511f70ae6a5a72) )
	ROM_LOAD32_BYTE( "mkt-ug19.bin", 0x000002, 0x80000, CRC(2d8c7ba1) SHA1(f891d6eb618dbf3e77f02e0f93da216e20571905) )
	ROM_LOAD32_BYTE( "mkt-uj19.bin", 0x000003, 0x80000, CRC(33b9b7a4) SHA1(e8ceca4c049e1f55d480a03ff793b595bd04d344) )

	ROM_LOAD32_BYTE( "mkt-ug16.bin", 0x200000, 0x80000, CRC(52c9d1e5) SHA1(7b1880fca0a11544782b70365c7dd96381ac48e7) )
	ROM_LOAD32_BYTE( "mkt-uj16.bin", 0x200001, 0x80000, CRC(c94c58cf) SHA1(974d75667eee779497325d5be8df937f15417edf) )
	ROM_LOAD32_BYTE( "mkt-ug20.bin", 0x200002, 0x80000, CRC(2f7e55d3) SHA1(bda6892ee6fcb46959e4d0892bbe7d9fc6072dd3) )
	ROM_LOAD32_BYTE( "mkt-uj20.bin", 0x200003, 0x80000, CRC(eae96df0) SHA1(b40532312ba61e4065abfd733dd0c93eecad48e9) )

	ROM_LOAD32_BYTE( "mkt-ug17.bin", 0x400000, 0x80000, CRC(e34fe253) SHA1(6b010bee795c1770297c9557ded1fe83425857f2) )
	ROM_LOAD32_BYTE( "mkt-uj17.bin", 0x400001, 0x80000, CRC(a56e12f5) SHA1(5db637c4710990cd06bb0069714b19621532e431) )
	ROM_LOAD32_BYTE( "mkt-ug22.bin", 0x400002, 0x80000, CRC(b537bb4e) SHA1(05a447deee2e89b49bdb3ca2161a021d7ec5f11e) )
	ROM_LOAD32_BYTE( "mkt-uj22.bin", 0x400003, 0x80000, CRC(5e12523b) SHA1(468f93ef9bb6addb45c1c939d24b6511f255426a) )
ROM_END

ROM_START( mktturbopi )
	ROM_REGION( 0x50000, "adpcm:cpu", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u3_sound_rom.u3", 0x10000, 0x40000, CRC(c615844c) SHA1(5732f9053a5f73b0cc3b0166d7dc4430829d5bc7) )

	ROM_REGION( 0x100000, "adpcm:oki", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u12_sound_rom.u12", 0x00000, 0x40000, CRC(258bd7f9) SHA1(463890b23f17350fb9b8a85897b0777c45bc2d54) )
	ROM_RELOAD(              0x40000, 0x40000 )
	ROM_LOAD( "sl1_mortal_kombat_u13_sound_rom.u13", 0x80000, 0x40000, CRC(7b7ec3b6) SHA1(6eec1b90d4a4855f34a7ebfbf93f3358d5627db4) )
	ROM_RELOAD(              0xc0000, 0x40000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "kombo-rompi-uj-12.bin", 0x00000, 0x80000, CRC(f4a9a289) SHA1(a94b0a5796457c6f2789e9fd5a1cb80fd6dcf22b) )
	ROM_LOAD16_BYTE( "kombo-rom-ug-12.bin", 0x00001, 0x80000, CRC(45bed5a1) SHA1(dba2c21878925afdcaf61520c18ebefd5e9617db) )
	ROM_FILL(0xF7914, 1, 0x60)
	ROM_FILL(0xF7915, 1, 0x09)

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "mkt-ug14.bin", 0x000000, 0x80000, CRC(9e00834e) SHA1(2b97b63f52ba1dba6af6ae56c223519a52b2ab9d) )
	ROM_LOAD32_BYTE( "mkt-uj14.bin", 0x000001, 0x80000, CRC(f4b0aaa7) SHA1(4cc6ee34c89e3cde325ad24b29511f70ae6a5a72) )
	ROM_LOAD32_BYTE( "mkt-ug19.bin", 0x000002, 0x80000, CRC(2d8c7ba1) SHA1(f891d6eb618dbf3e77f02e0f93da216e20571905) )
	ROM_LOAD32_BYTE( "mkt-uj19.bin", 0x000003, 0x80000, CRC(33b9b7a4) SHA1(e8ceca4c049e1f55d480a03ff793b595bd04d344) )

	ROM_LOAD32_BYTE( "mkt-ug16.bin", 0x200000, 0x80000, CRC(52c9d1e5) SHA1(7b1880fca0a11544782b70365c7dd96381ac48e7) )
	ROM_LOAD32_BYTE( "mkt-uj16.bin", 0x200001, 0x80000, CRC(c94c58cf) SHA1(974d75667eee779497325d5be8df937f15417edf) )
	ROM_LOAD32_BYTE( "mkt-ug20.bin", 0x200002, 0x80000, CRC(2f7e55d3) SHA1(bda6892ee6fcb46959e4d0892bbe7d9fc6072dd3) )
	ROM_LOAD32_BYTE( "mkt-uj20.bin", 0x200003, 0x80000, CRC(eae96df0) SHA1(b40532312ba61e4065abfd733dd0c93eecad48e9) )

	ROM_LOAD32_BYTE( "mkt-ug17.bin", 0x400000, 0x80000, CRC(e34fe253) SHA1(6b010bee795c1770297c9557ded1fe83425857f2) )
	ROM_LOAD32_BYTE( "mkt-uj17.bin", 0x400001, 0x80000, CRC(a56e12f5) SHA1(5db637c4710990cd06bb0069714b19621532e431) )
	ROM_LOAD32_BYTE( "mkt-ug22.bin", 0x400002, 0x80000, CRC(b537bb4e) SHA1(05a447deee2e89b49bdb3ca2161a021d7ec5f11e) )
	ROM_LOAD32_BYTE( "mkt-uj22.bin", 0x400003, 0x80000, CRC(5e12523b) SHA1(468f93ef9bb6addb45c1c939d24b6511f255426a) )
ROM_END

ROM_START( mk2r33 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12.l33", 0x00000, 0x80000, CRC(84cb0bf4) SHA1(098e0b5be75c60733f3a63893431506cb99f0981) )
	ROM_LOAD16_BYTE( "ug12.l33", 0x00001, 0x80000, CRC(2021ec4f) SHA1(7f357abd7ae66eda8eae2b318426da668cfe1deb) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( mk2v28b1 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12.v28", 0x00000, 0x80000, CRC(87a755b5) SHA1(d1796dfae89ca1163cb3db3638066d4bd54d32a8) )
	ROM_LOAD16_BYTE( "ug12.v28", 0x00001, 0x80000, CRC(b59368c4) SHA1(987ff2ee0944955289b6b156c375b183819072bd) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( umk2te50 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12.l50", 0x00000, 0x80000, CRC(62ef20f8) SHA1(0e0392bb4b59fb4e01369f533fdcfa6ee5fb6939) )
	ROM_LOAD16_BYTE( "ug12.l50", 0x00001, 0x80000, CRC(8c66e999) SHA1(ddb9f39149a7ded105f2e993a4c39c473067adf6) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( umk2te51 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12.l51", 0x00000, 0x80000, CRC(fbf97b24) SHA1(902614ce3a4527d1a78e148a876cd321ea221e8f) )
	ROM_LOAD16_BYTE( "ug12.l51", 0x00001, 0x80000, CRC(8d67c168) SHA1(699bf8e6924429221ace092fb66ae4c85eede8d2) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( umk2te52 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12.l52", 0x00000, 0x80000, CRC(a027088c) SHA1(10aced067d8e3a5fe905c07e2ee27904e3dd8855) )
	ROM_LOAD16_BYTE( "ug12.l52", 0x00001, 0x80000, CRC(474cf238) SHA1(fee96dc9390ade206be3768812040f3bb4ea1e2c) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( mkfr )
	ROM_REGION( 0x50000, "adpcm:cpu", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u3_sound_rom.u3", 0x10000, 0x40000, CRC(c615844c) SHA1(5732f9053a5f73b0cc3b0166d7dc4430829d5bc7) )

	ROM_REGION( 0x100000, "adpcm:oki", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u12_sound_rom.u12", 0x00000, 0x40000, CRC(258bd7f9) SHA1(463890b23f17350fb9b8a85897b0777c45bc2d54) )
	ROM_RELOAD(              0x40000, 0x40000 )
	ROM_LOAD( "sl1_mortal_kombat_u13_sound_rom.u13", 0x80000, 0x40000, CRC(7b7ec3b6) SHA1(6eec1b90d4a4855f34a7ebfbf93f3358d5627db4) )
	ROM_RELOAD(              0xc0000, 0x40000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "mkt-uj12f.bin", 0x00000, 0x80000, CRC(4192e38f) SHA1(abe2e6f643a36df48a23aaa2f9027c78c6078d2d) )
	ROM_LOAD16_BYTE( "mkt-ug12f.bin", 0x00001, 0x80000, CRC(8799979d) SHA1(4f094540e68c03fbd03cd8731797c55e455f61e6) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "mkt-ug14.bin", 0x000000, 0x80000, CRC(9e00834e) SHA1(2b97b63f52ba1dba6af6ae56c223519a52b2ab9d) )
	ROM_LOAD32_BYTE( "mkt-uj14.bin", 0x000001, 0x80000, CRC(f4b0aaa7) SHA1(4cc6ee34c89e3cde325ad24b29511f70ae6a5a72) )
	ROM_LOAD32_BYTE( "mkt-ug19.bin", 0x000002, 0x80000, CRC(2d8c7ba1) SHA1(f891d6eb618dbf3e77f02e0f93da216e20571905) )
	ROM_LOAD32_BYTE( "mkt-uj19.bin", 0x000003, 0x80000, CRC(33b9b7a4) SHA1(e8ceca4c049e1f55d480a03ff793b595bd04d344) )

	ROM_LOAD32_BYTE( "mkt-ug16.bin", 0x200000, 0x80000, CRC(52c9d1e5) SHA1(7b1880fca0a11544782b70365c7dd96381ac48e7) )
	ROM_LOAD32_BYTE( "mkt-uj16.bin", 0x200001, 0x80000, CRC(c94c58cf) SHA1(974d75667eee779497325d5be8df937f15417edf) )
	ROM_LOAD32_BYTE( "mkt-ug20.bin", 0x200002, 0x80000, CRC(2f7e55d3) SHA1(bda6892ee6fcb46959e4d0892bbe7d9fc6072dd3) )
	ROM_LOAD32_BYTE( "mkt-uj20.bin", 0x200003, 0x80000, CRC(eae96df0) SHA1(b40532312ba61e4065abfd733dd0c93eecad48e9) )

	ROM_LOAD32_BYTE( "mkt-ug17.bin", 0x400000, 0x80000, CRC(e34fe253) SHA1(6b010bee795c1770297c9557ded1fe83425857f2) )
	ROM_LOAD32_BYTE( "mkt-uj17.bin", 0x400001, 0x80000, CRC(a56e12f5) SHA1(5db637c4710990cd06bb0069714b19621532e431) )
	ROM_LOAD32_BYTE( "mkt-ug22.bin", 0x400002, 0x80000, CRC(b537bb4e) SHA1(05a447deee2e89b49bdb3ca2161a021d7ec5f11e) )
	ROM_LOAD32_BYTE( "mkt-uj22.bin", 0x400003, 0x80000, CRC(5e12523b) SHA1(468f93ef9bb6addb45c1c939d24b6511f255426a) )
ROM_END

ROM_START( mk2fr )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12fr.l31", 0x00000, 0x80000, CRC(0f801e9b) SHA1(b0dc620e1be6b89ff0a1dcd64eec678e81a2ea69) )
	ROM_LOAD16_BYTE( "ug12fr.l31", 0x00001, 0x80000, CRC(d896c9b6) SHA1(61e26c6acaf810e0788aef31000056e524b87b06) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END


HACK( 200?, mkturbod,   mk,  tunit_adpcm, mk,  midtunit_state, mktunit, ROT0, "Unknown", "Mortal Kombat (Turbo Ninja T-Unit 03/19/93, hack)", MACHINE_SUPPORTS_SAVE )
HACK( 2012, mktturboen, mk,  tunit_adpcm, mk,  midtunit_state, mktunit, ROT0, "Zenomorp", "Mortal Kombat (Turbo Endurance)(rev 5.0 T-Unit 03/19/93)", MACHINE_SUPPORTS_SAVE )
HACK( 2012, mktturbopi, mk,  tunit_adpcm, mk,  midtunit_state, mktunit, ROT0, "Zenomorp", "Mortal Kombat (Projectile Insanity)(rev 5.0 T-Unit 03/19/93)", MACHINE_SUPPORTS_SAVE )
HACK( 200?, mk2r33,     mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "Midway", "Mortal Kombat II (prototype)(rev L3.3)", MACHINE_SUPPORTS_SAVE )
HACK( 2014, umk2te50,   mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "SK", "Ultimate Mortal Kombat II (Tournament Edition r5.0.050)(rev L3.1)", MACHINE_SUPPORTS_SAVE )
HACK( 2014, umk2te51,   mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "SK", "Ultimate Mortal Kombat II (Tournament Edition r5.0.051)(rev L3.1)", MACHINE_SUPPORTS_SAVE )
HACK( 2014, umk2te52,   mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "SK", "Ultimate Mortal Kombat II (Tournament Edition r5.0.052)(rev L3.1)", MACHINE_SUPPORTS_SAVE )
HACK( 2007, mkfr,       mk,  tunit_adpcm, mk,  midtunit_state, mktunit, ROT0, "Arkatrad", "Mortal Kombat (Language Translation French)(rev 5.0 T-Unit 03/19/93)", MACHINE_SUPPORTS_SAVE )
HACK( 2007, mk2fr,      mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "Arkatrad", "Mortal Kombat II (Language Translation French)(12.02.2007)(Set 01)(rev L3.1)", MACHINE_SUPPORTS_SAVE )
HACK( 2017, mk2v28b1,   mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "Unknown", "Mortal Kombat II (Ver 2.8)(Beta 1)(rev L3.1)", MACHINE_SUPPORTS_SAVE )


// PSmame (c) gaston90 used with permission

 /****************************************************
         Proyecto Shadows Mame Build Plus
*****************************************************/

 /*************
 Mortal Kombat 
****************/

ROM_START( mks01 )
	ROM_REGION( 0x50000, "adpcm:cpu", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u3_sound_rom.u3", 0x10000, 0x40000, CRC(c615844c) SHA1(5732f9053a5f73b0cc3b0166d7dc4430829d5bc7) )

	ROM_REGION( 0x100000, "adpcm:oki", 0 )
	ROM_LOAD( "sl1_mortal_kombat_u12_sound_rom.u12", 0x00000, 0x40000, CRC(258bd7f9) SHA1(463890b23f17350fb9b8a85897b0777c45bc2d54) )
	ROM_RELOAD(              0x40000, 0x40000 )
	ROM_LOAD( "sl1_mortal_kombat_u13_sound_rom.u13", 0x80000, 0x40000, CRC(7b7ec3b6) SHA1(6eec1b90d4a4855f34a7ebfbf93f3358d5627db4) )
	ROM_RELOAD(              0xc0000, 0x40000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "mkt-uj12hc01.bin", 0x00000, 0x80000, CRC(2f47f224) SHA1(44c10853696507e0c73eaeb1d5bda095af9ae62f) )
	ROM_LOAD16_BYTE( "mkt-ug12hc01.bin", 0x00001, 0x80000, CRC(39dd89b7) SHA1(e2cfa470ed07824de2d1d43b7a6e7fb4bb8dacf3) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "mkt-ug14.bin", 0x000000, 0x80000, CRC(9e00834e) SHA1(2b97b63f52ba1dba6af6ae56c223519a52b2ab9d) )
	ROM_LOAD32_BYTE( "mkt-uj14.bin", 0x000001, 0x80000, CRC(f4b0aaa7) SHA1(4cc6ee34c89e3cde325ad24b29511f70ae6a5a72) )
	ROM_LOAD32_BYTE( "mkt-ug19.bin", 0x000002, 0x80000, CRC(2d8c7ba1) SHA1(f891d6eb618dbf3e77f02e0f93da216e20571905) )
	ROM_LOAD32_BYTE( "mkt-uj19.bin", 0x000003, 0x80000, CRC(33b9b7a4) SHA1(e8ceca4c049e1f55d480a03ff793b595bd04d344) )

	ROM_LOAD32_BYTE( "mkt-ug16.bin", 0x200000, 0x80000, CRC(52c9d1e5) SHA1(7b1880fca0a11544782b70365c7dd96381ac48e7) )
	ROM_LOAD32_BYTE( "mkt-uj16.bin", 0x200001, 0x80000, CRC(c94c58cf) SHA1(974d75667eee779497325d5be8df937f15417edf) )
	ROM_LOAD32_BYTE( "mkt-ug20.bin", 0x200002, 0x80000, CRC(2f7e55d3) SHA1(bda6892ee6fcb46959e4d0892bbe7d9fc6072dd3) )
	ROM_LOAD32_BYTE( "mkt-uj20.bin", 0x200003, 0x80000, CRC(eae96df0) SHA1(b40532312ba61e4065abfd733dd0c93eecad48e9) )

	ROM_LOAD32_BYTE( "mkt-ug17.bin", 0x400000, 0x80000, CRC(e34fe253) SHA1(6b010bee795c1770297c9557ded1fe83425857f2) )
	ROM_LOAD32_BYTE( "mkt-uj17.bin", 0x400001, 0x80000, CRC(a56e12f5) SHA1(5db637c4710990cd06bb0069714b19621532e431) )
	ROM_LOAD32_BYTE( "mkt-ug22.bin", 0x400002, 0x80000, CRC(b537bb4e) SHA1(05a447deee2e89b49bdb3ca2161a021d7ec5f11e) )
	ROM_LOAD32_BYTE( "mkt-uj22.bin", 0x400003, 0x80000, CRC(5e12523b) SHA1(468f93ef9bb6addb45c1c939d24b6511f255426a) )
ROM_END

 /****************
 Mortal Kombat II
*******************/

ROM_START( mk2fr01 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12hc01.l31", 0x00000, 0x80000, CRC(a80ca0a6) SHA1(2695e8394b99df89b03c52988e58a95ec37b0cc9) )
	ROM_LOAD16_BYTE( "ug12hc91.l31", 0x00001, 0x80000, CRC(d70f3631) SHA1(414fb8cc30b96ca77b2a65cfdfcf73e0d9953e48) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( mk2fr02 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12hc02.l31", 0x00000, 0x80000, CRC(a7e402a2) SHA1(bb0a9d9460db4e6af87164aac5f9ed74ba2ed741) )
	ROM_LOAD16_BYTE( "ug12hc92.l31", 0x00001, 0x80000, CRC(12a18f0e) SHA1(1b996e39b009b93d2e3845b2f8c5368b785b239d) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( mk2fr03 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12hc03.l31", 0x00000, 0x80000, CRC(ed8ea298) SHA1(aaf31bd70f1fdffd68b675467f1c98afb09508be) )
	ROM_LOAD16_BYTE( "ug12hc93.l31", 0x00001, 0x80000, CRC(ed87b26b) SHA1(dc15ac14b332899e73d578f4b4844c727257505a) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

ROM_START( mk2fr04 )
	ROM_REGION16_LE( 0xc00000, "dcs", ROMREGION_ERASEFF )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u2.u2", 0x000000, 0x80000, CRC(5f23d71d) SHA1(54c2afef243759e0f3dbe2907edbc4302f5c8bad) )
	ROM_RELOAD(                0x100000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u3.u3", 0x200000, 0x80000, CRC(d6d92bf9) SHA1(397351c6b707f2595e36360471015f9fa494e894) )
	ROM_RELOAD(                0x300000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u4.u4", 0x400000, 0x80000, CRC(eebc8e0f) SHA1(705ab63ff7672a4857d546afda6dca4973cce1ad) )
	ROM_RELOAD(                0x500000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u5.u5", 0x600000, 0x80000, CRC(2b0b7961) SHA1(1cdc64aab74d14afbd8c3531e3d0bd49271a281f) )
	ROM_RELOAD(                0x700000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u6.u6", 0x800000, 0x80000, CRC(f694b27f) SHA1(d43e38a124665f49ebb4ffc5a55e8f19a1a64686) )
	ROM_RELOAD(                0x900000, 0x80000 )
	ROM_LOAD16_BYTE( "l1_mortal_kombat_ii_sound_rom_u7.u7", 0xa00000, 0x80000, CRC(20387e0a) SHA1(505d05173b2a1f1ee3ebc2898ccd3a95c98dd04a) )
	ROM_RELOAD(                0xb00000, 0x80000 )

	ROM_REGION16_LE( 0x100000, "maincpu", 0 )
	ROM_LOAD16_BYTE( "uj12hc04.l31", 0x00000, 0x80000, CRC(0068bc9f) SHA1(6bdd7a01a029ea859e201cc7743e5dddea78741f) )
	ROM_LOAD16_BYTE( "ug12hc94.l31", 0x00001, 0x80000, CRC(1d387089) SHA1(bad95dde2f15f4807ec5a399dde93a8858f87fa0) )

	ROM_REGION( 0xc00000, "gfxrom", 0 )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug14.ug14", 0x000000, 0x100000, CRC(01e73af6) SHA1(6598cfd704cc92a7f358a0e1f1c973ab79dcc493) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj14.uj14", 0x000001, 0x100000, CRC(d4985cbb) SHA1(367865da7efae38d83de3c0868d02a705177ae63) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug19.ug19", 0x000002, 0x100000, CRC(fec137be) SHA1(f11ecb8a7993f5c4f4449564b4911f69bd6e9bf8) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj19.uj19", 0x000003, 0x100000, CRC(2d763156) SHA1(06536006da49ab5fb6b75b25f801b83fad000ff5) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug16.ug16", 0x400000, 0x100000, CRC(8ba6ae18) SHA1(465fe907de4a1e502180c4e41642998dd3abc8e6) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj16.uj16", 0x400001, 0x100000, CRC(39d885b4) SHA1(2251826d247c3c6df421124718401fb35a672f83) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug20.ug20", 0x400002, 0x100000, CRC(809118c1) SHA1(86153e648834c749e34573151cd4fee403a81962) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj20.uj20", 0x400003, 0x100000, CRC(b96824f0) SHA1(d42b122f9a57da330192abc7e5f97abc4065d718) )

	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug17.ug17", 0x800000, 0x100000, CRC(937d8620) SHA1(8b9f80a460b124a747a6d1495b53f01f580e28f1) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj17.uj17", 0x800001, 0x100000, CRC(218de160) SHA1(87aea173720d2a33d8183903f4fe8ba1d47e3348) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_ug22.ug22", 0x800002, 0x100000, CRC(154d53b1) SHA1(58ff0aa59101f40a9a3b5fbae1c904d0b0b31612) )
	ROM_LOAD32_BYTE( "l1_mortal_kombat_ii_game_rom_uj22.uj22", 0x800003, 0x100000, CRC(8891d785) SHA1(fd460df1ef8f4306ea42f7dc41488a80fd2c8f53) )
ROM_END

/*    YEAR  NAME            PARENT    MACHINE        INPUT       INIT             MONITOR COMPANY                 FULLNAME FLAGS */
// Mortal Kombat
HACK( 200?, mks01,       mk,  tunit_adpcm, mk,  midtunit_state, mktunit, ROT0, "S.Arkames", "Mortal Kombat (Language Translation French)(Alt)(rev 5.0 T-Unit 03/19/93)", MACHINE_SUPPORTS_SAVE )
// Mortal Kombat II
HACK( 2007, mk2fr01,     mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "S.Arkames", "Mortal Kombat II (Language Translation French)(12.02.2007)(Set 02)(rev L3.1)", MACHINE_SUPPORTS_SAVE )
HACK( 2007, mk2fr02,     mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "S.Arkames", "Mortal Kombat II (Language Translation French)(12.02.2007)(Set 03)(rev L3.1)", MACHINE_SUPPORTS_SAVE )
HACK( 2007, mk2fr03,     mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "S.Arkames", "Mortal Kombat II (Language Translation French)(12.02.2007)(Set 04)(rev L3.1)", MACHINE_SUPPORTS_SAVE )
HACK( 2007, mk2fr04,     mk2, tunit_dcs,   mk2, midtunit_state, mk2,     ROT0, "S.Arkames", "Mortal Kombat II (Language Translation French)(12.02.2007)(Set 05)(rev L3.1)", MACHINE_SUPPORTS_SAVE )


