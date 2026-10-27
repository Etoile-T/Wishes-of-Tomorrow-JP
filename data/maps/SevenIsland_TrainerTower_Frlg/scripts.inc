SevenIsland_TrainerTower_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TrainerTower_OnTransition
	.byte 0

SevenIsland_TrainerTower_OnTransition::
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerSign, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_EventScript_TrainerTowerAheadSign::
	msgbox SevenIsland_TrainerTower_Text_TrainerTowerAhead, MSGBOX_SIGN
	end

SevenIsland_TrainerTower_Text_DarioIntro::
	.string "{JPN}きみが くるのを かんじていた。$"

SevenIsland_TrainerTower_Text_DarioDefeat::
	.string "{JPN}まいった…$"

SevenIsland_TrainerTower_Text_DarioPostBattle::
	.string "{JPN}きみの みらいに おおくの\n"
	.string "であいが ある ことを かんじる。\p"
	.string "ふしぎな ちからで おたがいに\n"
	.string "むすばれて いくだろう。$"

SevenIsland_TrainerTower_Text_RodetteIntro::
	.string "{JPN}この しまの どこかで ふしぎな\n"
	.string "ポケモンたちが ねむっているの。$"

SevenIsland_TrainerTower_Text_RodetteDefeat::
	.string "{JPN}なんて すごい トレーナーなの!$"

SevenIsland_TrainerTower_Text_RodettePostBattle::
	.string "{JPN}この しまの どこかで ふしぎな\n"
	.string "ポケモンたちが ねむっているの。\p"
	.string "もしかして あなたを\n"
	.string "まっているのかも?$"

SevenIsland_TrainerTower_Text_TrainerTowerSign::
	.string "{JPN}トレーナータワー いりぐち\n"
	.string "トレーナーよ ちょうせんせよ!$"

SevenIsland_TrainerTower_Text_TrainerTowerAhead::
	.string "{JPN}この さき トレーナータワー$"

