Route11_EastEntrance_1F_Frlg_MapScripts::
	.byte 0

Route11_EastEntrance_1F_EventScript_TopGuard::
	msgbox Route11_EastEntrance_1F_Text_ManInLavenderRatesNames, MSGBOX_NPC
	end

Route11_EastEntrance_1F_EventScript_BottomGuard::
	msgbox Route11_EastEntrance_1F_Text_RockTunnelToReachLavender, MSGBOX_NPC
	end

@ Unclear where this is originally from
Route11_EastEntrance_1F_Text_BagIsFull::
	.string "{JPN}{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}の バッグ\n"
	.string "いっぱい みたい だね$"

Route11_EastEntrance_1F_Text_ManInLavenderRatesNames::
	.string "{JPN}ポケモンに いい なまえを\n"
	.string "つけるのって むずかしいよね?\p"
	.string "とくに たくさん つかまえた\n"
	.string "ときなんかは?\p"
	.string "シオンタウンには ポケモンの\n"
	.string "ニックネームを うらなう ひとが いるよ\p"
	.string "ポケモンの なまえを かえる\n"
	.string "てつだいも してくれるんだ$"

Route11_EastEntrance_1F_Text_RockTunnelToReachLavender::
	.string "{JPN}シオンタウンを めざすなら\n"
	.string "イワヤマトンネルを とおるといい\p"
	.string "イワヤマトンネルには\n"
	.string "ハナダシティから いけるよ$"

