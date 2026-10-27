FiveIsland_ResortGorgeous_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
	.byte 0

FiveIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FiveIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

FiveIsland_ResortGorgeous_Text_DaisyIntro::
	.string "{JPN}この てで わたしの しょうりを\n"
	.string "えがいて みせるわ!$"

FiveIsland_ResortGorgeous_Text_DaisyDefeat::
	.string "{JPN}なんて はずかしい…\n"
	.string "かおが まっかだわ…$"

FiveIsland_ResortGorgeous_Text_DaisyPostBattle::
	.string "{JPN}あらら えのぐが\n"
	.string "そこらじゅうに ちらばっちゃった!$"

FiveIsland_ResortGorgeous_Text_CelinaIntro::
	.string "{JPN}ちょっと!\n"
	.string "いま えを かいてるの。\l"
	.string "しかいに はいらないで ちょうだい!$"

FiveIsland_ResortGorgeous_Text_CelinaDefeat::
	.string "{JPN}この まけ…\n"
	.string "めのまえが まっしろに なりそう…$"

FiveIsland_ResortGorgeous_Text_CelinaPostBattle::
	.string "{JPN}ジリアン?\n"
	.string "すこし くびを かしげて…\l"
	.string "そう! その かおよ!$"

FiveIsland_ResortGorgeous_Text_RaynaIntro::
	.string "{JPN}うーん…\n"
	.string "アングルが いまひとつ なのよね…$"

FiveIsland_ResortGorgeous_Text_RaynaDefeat::
	.string "{JPN}ああ…\n"
	.string "きもちが ブルーだわ…$"

FiveIsland_ResortGorgeous_Text_RaynaPostBattle::
	.string "{JPN}そらと うみ…\n"
	.string "どちらも きまぐれね。\p"
	.string "ひょうじょうが かわるから\n"
	.string "えに するのが むずかしいの。$"

FiveIsland_ResortGorgeous_Text_JackiIntro::
	.string "{JPN}ともだちの べっそうに あそびに きたの。\n"
	.string "しりたいなら おしえて あげるわ。$"

FiveIsland_ResortGorgeous_Text_JackiDefeat::
	.string "{JPN}あら まあ つよいのね。$"

FiveIsland_ResortGorgeous_Text_JackiPostBattle::
	.string "{JPN}おだやかな しおかぜの なか のんびり\n"
	.string "バトルするのって きもちいいわ。$"

FiveIsland_ResortGorgeous_Text_GillianIntro::
	.string "{JPN}ポケモンせんようの プールを\n"
	.string "つくろうかと おもってますの。$"

FiveIsland_ResortGorgeous_Text_GillianDefeat::
	.string "{JPN}まあ なんて こと!$"

FiveIsland_ResortGorgeous_Text_GillianPostBattle::
	.string "{JPN}プールも いいけれど サンルームも\n"
	.string "すてきかも しれませんわね。$"

FiveIsland_ResortGorgeous_Text_DestinIntro::
	.string "{JPN}ぼく はしるのが とくい!\n"
	.string "すごく はやいんだよ!$"

FiveIsland_ResortGorgeous_Text_DestinDefeat::
	.string "{JPN}おっと!\n"
	.string "あせっちゃった!$"

FiveIsland_ResortGorgeous_Text_DestinPostBattle::
	.string "{JPN}かぜと いっしょに はしると\n"
	.string "そらを とべそうな きが するんだ!$"

FiveIsland_ResortGorgeous_Text_TobyIntro::
	.string "{JPN}いやはや この リゾートの うみの\n"
	.string "いきものは ぼくの しょうに あうね。$"

FiveIsland_ResortGorgeous_Text_TobyDefeat::
	.string "{JPN}これは おどろいた!\n"
	.string "じょうだんだろう。$"

FiveIsland_ResortGorgeous_Text_TobyPostBattle::
	.string "{JPN}こんな ことで むきに なるなんて…\n"
	.string "ばかばかしい。$"

FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
	.string "{JPN}セルフィ: ありがとう。\p"
	.string "もう かえって いいわよ。$"

FiveIsland_ResortGorgeous_Text_SelphysHouse::
	.string "{JPN}セルフィの いえ$"

