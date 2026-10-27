.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_Frlg_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_SEEN_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route2_EastBuilding_Text_GreatHereYouGo
	checkitemspace ITEM_HM05
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM05
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_GiveHM05IfSeen10Mons::
	.string "{JPN}やあ! おぼえてる?\n"
	.string "オーキドはかせの じょしゅだよ。\p"
	.string "ずかんに 10しゅるいの ポケモンの\n"
	.string "データが そろったら\l"
	.string "ごほうびを わたすことに なってるんだ。\p"
	.string "はかせから きみにと\n"
	.string "ひでんマシン05を あずかってるよ。\p"
	.string "それで {ENG}{PLAYER}{JPN} きいても いいかな。\p"
	.string "すくなくとも 10しゅるいの\n"
	.string "ポケモンの データを あつめたかい?$"

Route2_EastBuilding_Text_GreatHereYouGo::
	.string "{JPN}すごい! つかまえた ポケモンは\n"
	.string "{ENG}{STR_VAR_3}{JPN}しゅるいだね!\p"
	.string "おめでとう!\n"
	.string "はい どうぞ!$"

Route2_EastBuilding_Text_ReceivedHM05FromAide::
	.string "{JPN}{ENG}{PLAYER}{JPN}は じょしゅから\n"
	.string "ひでんマシン05を もらった!$"

Route2_EastBuilding_Text_ExplainHM05::
	.string "{JPN}ひでんマシン05の なかみは\n"
	.string "フラッシュだよ。\p"
	.string "フラッシュを つかえば くらい\n"
	.string "どうくつも あかるく てらせるんだ。$"

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
	.string "{JPN}ポケモンが フラッシュを おぼえたら\n"
	.string "イワヤマトンネルを とおれるよ。$"

