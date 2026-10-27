Route16_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_RemoveSnorlax
	end

Route16_EventScript_RemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route16_OnTransitionCyclingRoad
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route16_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_LaoIntro::
	.string "{JPN}なんの ようだ?$"

Route16_Text_LaoDefeat::
	.string "{JPN}わらったら ゆるさねえぞ!$"

Route16_Text_LaoPostBattle::
	.string "{JPN}おれたちは ここで たむろするのが すきなんだ\n"
	.string "もんくあるか?$"

Route16_Text_KojiIntro::
	.string "{JPN}いい じてんしゃだな!\n"
	.string "よこせよ!$"

Route16_Text_KojiDefeat::
	.string "{JPN}ノックアウト!$"

Route16_Text_KojiPostBattle::
	.string "{JPN}もういい じてんしゃなんか いるか!$"

Route16_Text_LukeIntro::
	.string "{JPN}でてこいよ こねずみちゃん!$"

Route16_Text_LukeDefeat::
	.string "{JPN}この ちびねずみめ!$"

Route16_Text_LukePostBattle::
	.string "{JPN}まけるのは だいきらいだ!\n"
	.string "めのまえから きえろ!$"

Route16_Text_HideoIntro::
	.string "{JPN}おい いま ぶつかった だろ!$"

Route16_Text_HideoDefeat::
	.string "{JPN}ドカーン!$"

Route16_Text_HideoPostBattle::
	.string "{JPN}おまえが いやでも おれたちは\n"
	.string "ずっと ここに たむろしてるぜ\p"
	.string "セキチクから かいがんぞいに\n"
	.string "クチバへ まわりみち できるぜ$"

Route16_Text_CamronIntro::
	.string "{JPN}はらぺこで きげんが わるいんだ!\n"
	.string "サンドバッグが ほしいぜ!$"

Route16_Text_CamronDefeat::
	.string "{JPN}だめだ だめだ だめだ!$"

Route16_Text_CamronPostBattle::
	.string "{JPN}どうせ ポケモンを もつなら\n"
	.string "どうもうな やつが いい\p"
	.string "てきを ずたずたに\n"
	.string "してやるのさ$"

Route16_Text_RubenIntro::
	.string "{JPN}よう!\n"
	.string "たのしく やろうぜ!$"

Route16_Text_RubenDefeat::
	.string "{JPN}おこらせるなよ!$"

Route16_Text_RubenPostBattle::
	.string "{JPN}くさい ポケモンで ひとに いやがらせ\n"
	.string "するのが たのしいんだ\p"
	.string "ひとを おどかすのに ぴったりだぜ\n"
	.string "それに かみつくしな$"

Route16_Text_MonSprawledOutInSlumber::
	.string "{JPN}ポケモンが ねそべって\n"
	.string "きもちよさそうに ぐっすり ねている$"

Route16_Text_CyclingRoadSign::
	.string "{JPN}さかみちを たのしもう!\n"
	.string "サイクリングロード$"

Route16_Text_RouteSign::
	.string "{JPN}16ばんどうろ\n"
	.string "タマムシシティ - セキチクシティ$"

Route16_Text_JedIntro::
	.string "{JPN}ジェド: ぼくらの あいに かぎりは ない\n"
	.string "あいしあってるから みせつけるのさ!$"

Route16_Text_JedDefeat::
	.string "{JPN}ジェド: しまった!\n"
	.string "まける ところを かのじょに みられた!$"

Route16_Text_JedPostBattle::
	.string "{JPN}ジェド: ねえ レア\n"
	.string "ぼくばかり みてちゃ だめだよ$"

Route16_Text_JedNotEnoughMons::
	.string "{JPN}ジェド: ポケモン 1ぴきだけ?\n"
	.string "きみの こころに あいは ないの?$"

Route16_Text_LeaIntro::
	.string "{JPN}レア: ときどき わたしたちの あいの\n"
	.string "はげしさが こわくなるの$"

Route16_Text_LeaDefeat::
	.string "{JPN}レア: ああっ! でも ジェドは\n"
	.string "まけても かっこいい!$"

Route16_Text_LeaPostBattle::
	.string "{JPN}レア: えへへ ごめんね\n"
	.string "ジェドって ほんと かっこいいの$"

Route16_Text_LeaNotEnoughMons::
	.string "{JPN}レア: あら ポケモンを 2ひき\n"
	.string "つれてないの?\p"
	.string "あなたも ポケモンも\n"
	.string "さびしく ないの?$"
