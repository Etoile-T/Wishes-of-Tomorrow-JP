VermilionCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_EventScript_VSSeekerWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VS_SEEKER, VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain
	setflag FLAG_GOT_VS_SEEKER
	giveitem ITEM_VS_SEEKER
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches
	release
	end

VermilionCity_PokemonCenter_1F_EventScript_ExplainVSSeeker::
	msgbox VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker
	release
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
	.string "{JPN}おなじ レベルでも ポケモンの\n"
	.string "のうりょくや とくせいは\l"
	.string "ぜんぜん ちがう ことが あるんだ。\p"
	.string "トレーナーが そだてた ポケモンは\n"
	.string "やせいの ポケモンより つよいよ。$"

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
	.string "{JPN}ぼくの ポケモンが どくに なって!\n"
	.string "あるいてる あいだに ひんしに!$"

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
	.string "{JPN}たしかに レベルが たかい\n"
	.string "ポケモンの ほうが つよい…\p"
	.string "でも どの ポケモンにも にがてな\n"
	.string "タイプが あるんだ。\p"
	.string "だから どんな あいてにも つよい\n"
	.string "ポケモンは いない みたいだね。$"

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
	.string "{JPN}いちど たたかった あいてと\n"
	.string "また たたかいたく なる きもち…\p"
	.string "そんな きもちに なった こと ない?\n"
	.string "きっと あるよね。\p"
	.string "わたしも なんども たたかいたい\n"
	.string "あいてが いたの。\p"
	.string "だから これを くばってるのよ。\n"
	.string "ひとつ どうぞ!$"

VermilionCity_PokemonCenter_1F_Text_UseDeviceForRematches::
	.string "{JPN}それを つかえば さいせんを\n"
	.string "のぞむ トレーナーが みつかるわ。\p"
	.string "でも つかうには バッテリーを\n"
	.string "じゅうでん しないと だめなの。$"

VermilionCity_PokemonCenter_1F_Text_ExplainVSSeeker::
	.string "{JPN}バトルサーチャーの つかいかた?\n"
	.string "かんたんよ。\p"
	.string "ピピピッて つかうと まわりの\n"
	.string "トレーナーが きづくの。\p"
	.string "さいせんを したい トレーナーが いれば\n"
	.string "すぐに おしえて くれるわ。\p"
	.string "じゅうでん したら どうろで\n"
	.string "つかってね。$"
