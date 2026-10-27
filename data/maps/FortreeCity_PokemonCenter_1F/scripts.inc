FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "{JPN}きみぃ\n"
	.string "ポケモンずかん つくっておるのか?\p"
	.string "ふむぅ…… サファリゾーンに\n"
	.string "いっては どうかな?$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "{JPN}レコードコーナーで\n"
	.string "なにか やってみた?\p"
	.string "けっこう いいよ トレーナーの\n"
	.string "レコードを まぜあわせるんだ\p"
	.string "しくみは よく わからないけど\n"
	.string "かっこいいし ワクワク するよ!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "{JPN}わあ ポケナビ もってるんだ!\n"
	.string "わたしのと おなじだね!\p"
	.string "ポケナビの エントリーコールって\n"
	.string "しってる?\p"
	.string "それを つかえば とうろくした\n"
	.string "トレーナーと いつでも はなせるの\p"
	.string "さいせんを したがってる トレーナーも\n"
	.string "おしえてくれるんだよ\p"
	.string "ほんと べんり! デボンの ひとたちって\n"
	.string "さすが よく わかってるよね!$"

