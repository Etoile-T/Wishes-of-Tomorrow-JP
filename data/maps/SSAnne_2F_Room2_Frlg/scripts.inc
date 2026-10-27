SSAnne_2F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleIntro, SSAnne_2F_Room2_Text_DaleDefeat
	msgbox SSAnne_2F_Room2_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksIntro, SSAnne_2F_Room2_Text_BrooksDefeat
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_BrooksIntro::
	.string "{JPN}わかものと たたかうと\n"
	.string "わかがえるのじゃ。$"

SSAnne_2F_Room2_Text_BrooksDefeat::
	.string "{JPN}よい しょうぶ じゃった!\n"
	.string "ああ わかがえった きぶんじゃ!$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
	.string "{JPN}15ねん まえ なら\n"
	.string "わしが かって おったわい!$"

SSAnne_2F_Room2_Text_DaleIntro::
	.string "{JPN}おれが つりあげた やつを みてくれ!$"

SSAnne_2F_Room2_Text_DaleDefeat::
	.string "{JPN}もう からっきしだ!$"

SSAnne_2F_Room2_Text_DalePostBattle::
	.string "{JPN}パーティ?\p"
	.string "ふねの パーティなら もう\n"
	.string "おわってる ころだぜ。$"

