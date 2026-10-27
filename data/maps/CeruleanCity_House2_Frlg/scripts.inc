CeruleanCity_House2_Frlg_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
	.string "{JPN}あの にくらしい ロケットだんめ!\p"
	.string "わしの いえを こんなに\n"
	.string "しおって!\p"
	.string "ポケモンに あなをほるを おしえる\n"
	.string "わざマシンを ぬすまれたんじゃ!\p"
	.string "マンキーか サンドに\n"
	.string "つかおうと おもっとったのに…\p"
	.string "たかかったんじゃぞ あれは!$"

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
	.string "{JPN}なくした ものは しかたない。\p"
	.string "わざマシン なしで ディグダに\n"
	.string "あなをほるを おしえる ことにした。$"

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
	.string "{JPN}ロケットだんは あなを ほって\n"
	.string "わるさを しようと してるに ちがいない!$"

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
	.string "{JPN}ロケットだんが ぬけみちを のこしていった!$"

