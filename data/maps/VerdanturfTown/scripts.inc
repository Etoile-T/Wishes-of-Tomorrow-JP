VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "{JPN}パパに きいたんだけどね。\p"
	.string "この トンネルには おくびょうな\n"
	.string "ポケモンが たくさん いるんだって。\p"
	.string "おおきな おとで びっくりして\n"
	.string "おおさわぎに なっちゃうんだって。\p"
	.string "だから おおきな トンネルの こうじは\n"
	.string "やめなきゃ いけなかったんだって。\p"
	.string "でも ひとりだけ じぶんで トンネルを\n"
	.string "ほろうと している おとこのひとが いるの!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "{JPN}すきな おんなのひとの ために\n"
	.string "トンネルを ほった ひとが いたの。\p"
	.string "よく わからないけど すごいね!$"

VerdanturfTown_Text_AirCleanHere:
	.string "{JPN}かざむきの かんけいで このまち には\n"
	.string "かざんばいが とんでくることは ない!\p"
	.string "ここの くうきは きれいで おいしい。\n"
	.string "ここで くらせば からだの よわいひとも\l"
	.string "びょうきがちなひとも げんきに なれそうさ。$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "{JPN}ぼくと ぼくの ポケモンは\n"
	.string "さいきん れんしょう つづきでね。\p"
	.string "この まちの バトルテントで\n"
	.string "デビューすることに きめたんだ!$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "{JPN}フレンドリィ ショップの となりに\n"
	.string "どうくつが あるだろ?\p"
	.string "なかを ふさいでいる いわを こわし\n"
	.string "とおれるように しようと がんばっている\l"
	.string "やつが いるんだ!\p"
	.string "とおれるように なると いいのに……\n"
	.string "カナズミにも いきやすく なるから!$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "{JPN}フレンドリィ ショップの となりの\n"
	.string "どうくつが とおれるように なっただろ!\p"
	.string "カナズミまで デボンの しんせいひんを\n"
	.string "かいに いきやすくなって うれしいよ!$"

VerdanturfTown_Text_TownSign:
	.string "{JPN}シダケタウン\p"
	.string "「かぜの ふく こうげんに\n"
	.string "くさが あまく かおる まち」$"

VerdanturfTown_Text_WandasHouse:
	.string "{JPN}「ミチルの いえ」$"

VerdanturfTown_Text_BattleTentSign:
	.string "{JPN}バトルテント シダケタウン かいじょう\n"
	.string "みまもれ! ポケモンバトル$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "{JPN}カナシダトンネル\n"
	.string "「カナズミと シダケを つなぐ」\p"
	.string "「トンネルの こうじは\n"
	.string "ちゅうしに なりました」$"

