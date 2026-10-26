VerdanturfTown_House_MapScripts::
	.byte 0

VerdanturfTown_House_EventScript_Woman1::
	msgbox VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague, MSGBOX_NPC
	end

VerdanturfTown_House_EventScript_Woman2::
	msgbox VerdanturfTown_House_Text_DefeatEliteFourInARow, MSGBOX_NPC
	end

VerdanturfTown_House_Text_TrainersGatherAtPokemonLeague:
	.string "{JPN}はるか とおく サイユウシティの おくに\n"
	.string "ポケモンリーグが あるんだ。\p"
	.string "そこに あつまる トレーナーは\n"
	.string "みんな おそろしいほどの うでまえさ。$"

VerdanturfTown_House_Text_DefeatEliteFourInARow:
	.string "{JPN}ポケモンリーグでは してんのうと\n"
	.string "れんぞくで たたかわないと いけない\l"
	.string "ルールだったと おもうよ。\p"
	.string "だれか ひとりにでも まけたら\n"
	.string "さいしょの ひとから\l"
	.string "ちょうせん しなおしなんだ。$"

