BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	chooseboxmon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "{JPN}えへへ!\n"
	.string "ポケモンの きもち わかるの!\p"
	.string "ねえねえ!\n"
	.string "ポケモン みせて くれる?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "{JPN}ぶー!\n"
	.string "けちんぼ!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ たたかうの ちゅき! って!\n"
	.string "いっぱい いたいいたい でも\l"
	.string "たたかうよ! って!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ たたかうの ちゅき! って!\n"
	.string "でも あんまし いたいいたい だと\l"
	.string "じぶんが ちんぱい なるよ! って!$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ たたかうの ちゅき! って!\n"
	.string "でも あんまし いたいいたい だと\l"
	.string "ずるいの するよ! って!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ じぶん だいじ! って!\n"
	.string "でも あんまし いたいいたい だと\l"
	.string "ちかえし してやる! って!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ じぶん だいじ! って!\n"
	.string "いっぱい いたいいたい でも\l"
	.string "じぶん だいじ! って!$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ じぶん だいじ! って!\n"
	.string "でも あんまし いたいいたい だと\l"
	.string "ずるいの するよ! って!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ ずるいの ちゅき! って!\n"
	.string "でも あんまし いたいいたい だと\l"
	.string "ちかえし してやる! って!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ ずるいの ちゅき! って!\n"
	.string "でも あんまし いたいいたい だと\l"
	.string "じぶんが ちんぱい なるよ! って!$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "{JPN}ふんふん……\p"
	.string "このこ ずるいの ちゅき! って!\n"
	.string "いっぱい いたいいたい でも\l"
	.string "ずるいのが いい! って!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "{JPN}たまごは ねんね してる から\n"
	.string "おはなち できない よぉ!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "{JPN}ポケモンの きもちが わかるとは\n"
	.string "あの おじょうちゃん なかなか\l"
	.string "シャレた ことを もうしますな!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "{JPN}じぶん あのこが すごく だいじなことを\n"
	.string "いっている きが するで あります!$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "{JPN}ぼく ちってるぜ!\p"
	.string "あのこ あかい おうちで\n"
	.string "よく あそんでる!$"

