RockTunnel_B1F_Frlg_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaIntro, RockTunnel_B1F_Text_SofiaDefeat
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaIntro, RockTunnel_B1F_Text_MarthaDefeat
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleyIntro, RockTunnel_B1F_Text_DudleyDefeat
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_HIKER_ALLEN, RockTunnel_B1F_Text_AllenIntro, RockTunnel_B1F_Text_AllenDefeat
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_HIKER_ERIC, RockTunnel_B1F_Text_EricIntro, RockTunnel_B1F_Text_EricDefeat
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperIntro, RockTunnel_B1F_Text_CooperDefeat
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveIntro, RockTunnel_B1F_Text_SteveDefeat
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonIntro, RockTunnel_B1F_Text_WinstonDefeat
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_SofiaIntro::
	.string "{JPN}やまで まよわない ほうほうを\n"
	.string "しってる?\p"
	.string "こえだを おって めじるしに\n"
	.string "するのよ。$"

RockTunnel_B1F_Text_SofiaDefeat::
	.string "{JPN}ああん!\n"
	.string "がんばったのに!$"

RockTunnel_B1F_Text_SofiaPostBattle::
	.string "{JPN}おうちに かえりたい!$"

RockTunnel_B1F_Text_DudleyIntro::
	.string "{JPN}ハハハ!\n"
	.string "おれの パワーに かてるか?$"

RockTunnel_B1F_Text_DudleyDefeat::
	.string "{JPN}おっと!\n"
	.string "ちからまけだ!$"

RockTunnel_B1F_Text_DudleyPostBattle::
	.string "{JPN}かんがえるのが きらいだから\n"
	.string "パワー いっぽん なんだ。$"

RockTunnel_B1F_Text_CooperIntro::
	.string "{JPN}ポケモンずかん もってるの?\n"
	.string "いいなあ ほしいなあ。$"

RockTunnel_B1F_Text_CooperDefeat::
	.string "{JPN}ちぇっ!\n"
	.string "うらやましい!$"

RockTunnel_B1F_Text_CooperPostBattle::
	.string "{JPN}ずかんが かんせい したら\n"
	.string "ちょうだい?$"

RockTunnel_B1F_Text_SteveIntro::
	.string "{JPN}あの… ポケモンの コスプレって\n"
	.string "しってる?$"

RockTunnel_B1F_Text_SteveDefeat::
	.string "{JPN}まあ そういう ことで。$"

RockTunnel_B1F_Text_StevePostBattle::
	.string "{JPN}ポケモンの コスプレは ポケモンの\n"
	.string "かっこうを して たのしむ ことさ。\p"
	.string "ピッピが にんきなんだ。$"

RockTunnel_B1F_Text_AllenIntro::
	.string "{JPN}おれの ポケモンの テクニックで\n"
	.string "なかせて やるぜ!$"

RockTunnel_B1F_Text_AllenDefeat::
	.string "{JPN}まいった!\n"
	.string "きみの ほうが うわてだ!$"

RockTunnel_B1F_Text_AllenPostBattle::
	.string "{JPN}やまには いわタイプの\n"
	.string "ポケモンが よく いるよ。$"

RockTunnel_B1F_Text_MarthaIntro::
	.string "{JPN}ここには あまり こないけど\n"
	.string "しょうぶ してあげる。$"

RockTunnel_B1F_Text_MarthaDefeat::
	.string "{JPN}あっ!\n"
	.string "まけちゃった!$"

RockTunnel_B1F_Text_MarthaPostBattle::
	.string "{JPN}ちいさい ポケモンが すき。\n"
	.string "おおきいのは こわすぎるもん!$"

RockTunnel_B1F_Text_EricIntro::
	.string "{JPN}ぜんりょくで かかってこい!$"

RockTunnel_B1F_Text_EricDefeat::
	.string "{JPN}やられた!$"

RockTunnel_B1F_Text_EricPostBattle::
	.string "{JPN}ポケモンを きたえて おまえのに\n"
	.string "かって やるからな。$"

RockTunnel_B1F_Text_WinstonIntro::
	.string "{JPN}いえでは ポケモンの\n"
	.string "イラストを かいてるんだ。$"

RockTunnel_B1F_Text_WinstonDefeat::
	.string "{JPN}ふう…\n"
	.string "つかれた…$"

RockTunnel_B1F_Text_WinstonPostBattle::
	.string "{JPN}がかで あって せんしじゃ ないんだ。\n"
	.string "いえに かえって えを かこう。$"

