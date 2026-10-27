Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "{JPN}そこの カナシダトンネル……\p"
	.string "さいしょは おおぜいの さぎょういんが\n"
	.string "さいしんの きかいで いわを ほってた\l"
	.string "でも やめるしか なかった\p"
	.string "この あたりの やせいの ポケモンに\n"
	.string "わるい えいきょうを あたえることが\l"
	.string "わかったんだ\p"
	.string "だから おれたちは ここで\n"
	.string "ゴロゴロ するしか ないのさ$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "{JPN}シダケに むかって たった ひとりで\n"
	.string "トンネルを ほっている おとこが いる\l"
	.string "ひっしに ほりぬこうと してるんだ\p"
	.string "きかいを つかわず すこしずつ ほれば\n"
	.string "ポケモンを さわがせず\l"
	.string "しぜんかんきょうを こわさずに\l"
	.string "すむって いうんだよ\p"
	.string "もう ほりぬけたのかなあ$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "{JPN}トンネルを つかわずに シダケに\n"
	.string "いくなら うみを わたって ムロへ\l"
	.string "そこから ふねで カイナへ いって\l"
	.string "キンセツを とおって いくしか ないな$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "{JPN}きいたか? シダケまでの トンネルが\n"
	.string "つうじた らしいぞ!\p"
	.string "つよく ねがい つづければ\n"
	.string "ゆめは かなう ことも あるんだな$"

