Route18_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route18_OnTransitionCyclingRoad
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_Text_WiltonIntro::
	.string "{JPN}あたらしい ポケモンを もとめて\n"
	.string "くさむらは ぜんぶ チェックしてるんだ!$"

Route18_Text_WiltonDefeat::
	.string "{JPN}ちぇっ!$"

Route18_Text_WiltonPostBattle::
	.string "{JPN}じてんしゃが あったらなあ!$"

Route18_Text_RamiroIntro::
	.string "{JPN}クルックー!\n"
	.string "ぼくの とりの なきまね どうだい?$"

Route18_Text_RamiroDefeat::
	.string "{JPN}ちょっと からかいたかったんだ!$"

Route18_Text_RamiroPostBattle::
	.string "{JPN}うみが ちかいから しゅうまつは\n"
	.string "うみの ポケモンを あつめてるんだ。$"

Route18_Text_JacobIntro::
	.string "{JPN}ここは おれの なわばりだ!\n"
	.string "とっとと でていけ!$"

Route18_Text_JacobDefeat::
	.string "{JPN}くそっ!$"

Route18_Text_JacobPostBattle::
	.string "{JPN}ここは ポケモンを つかまえるのに\n"
	.string "おきにいりの ばしょなんだ。$"

Route18_Text_RouteSign::
	.string "{JPN}ここは 18ばんどうろ\n"
	.string "タマムシシティ - セキチクシティ$"

Route18_Text_CyclingRoadSign::
	.string "{JPN}サイクリングロード\n"
	.string "ほこうしゃの つうこうは きんし!$"

