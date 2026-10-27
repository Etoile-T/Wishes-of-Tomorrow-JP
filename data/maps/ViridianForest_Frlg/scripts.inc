ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
	.string "{JPN}ともだちと いっしょに むしポケモンを\n"
	.string "つかまえに きたんだ!\p"
	.string "みんな ポケモンしょうぶが\n"
	.string "したくて うずうず してるよ!$"

ViridianForest_Text_RickIntro::
	.string "{JPN}おっ! ポケモン もってるな!\n"
	.string "さあ こい!\l"
	.string "しょうぶ しようぜ!$"

ViridianForest_Text_RickDefeat::
	.string "{JPN}うわっ!\nキャタピーじゃ かなわない!$"

ViridianForest_Text_RickPostBattle::
	.string "{JPN}シーッ! むしが にげちゃうよ。\n"
	.string "また こんどね?$"

ViridianForest_Text_DougIntro::
	.string "{JPN}よう!\n"
	.string "ポケモントレーナーなら\l"
	.string "にげられないぞ!$"

ViridianForest_Text_DougDefeat::
	.string "{JPN}あれ?\n"
	.string "ポケモンが いなくなっちゃった!$"

ViridianForest_Text_DougPostBattle::
	.string "{JPN}ちぇっ くやしい! もっと つよいのを\n"
	.string "つかまえて やる!$"

ViridianForest_Text_SammyIntro::
	.string "{JPN}ちょっと まって!\n"
	.string "なにを そんなに いそいでるの?$"

ViridianForest_Text_SammyDefeat::
	.string "{JPN}まいった!\n"
	.string "きみ つよいね!$"

ViridianForest_Text_SammyPostBattle::
	.string "{JPN}じめんに ものが おちてる\n"
	.string "ことが あるんだ。\p"
	.string "ぼく おとしものを さがしてるんだ。\n"
	.string "てつだって くれる?$"

ViridianForest_Text_AnthonyIntro::
	.string "{JPN}ちいさいからって てかげん したら\n"
	.string "ゆるさないからね!$"

ViridianForest_Text_AnthonyDefeat::
	.string "{JPN}ちぇー。\n"
	.string "ぜんぜん だめだった。$"

ViridianForest_Text_AnthonyPostBattle::
	.string "{JPN}おこづかい へっちゃった…$"

ViridianForest_Text_CharlieIntro::
	.string "{JPN}ポケモンが しんかするって しってた?$"

ViridianForest_Text_CharlieDefeat::
	.string "{JPN}あっ!\n"
	.string "まけちゃった!$"

ViridianForest_Text_CharliePostBattle::
	.string "{JPN}むしポケモンは すぐ しんかするよ。\n"
	.string "すごく たのしいんだ!$"

ViridianForest_Text_RanOutOfPokeBalls::
	.string "{JPN}ポケモンを つかまえようと ボールを\n"
	.string "なげてたら なくなっちゃった。\p"
	.string "だから モンスターボールは いくつ\n"
	.string "あっても こまらないんだ。$"

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "ポケモンが よわくて しょうぶを\n"
	.string "さけたい ときは くさむらに\l"
	.string "ちかづかないように!$"

ViridianForest_Text_UseAntidoteForPoison::
	.string "{JPN}どくには どくけし!\n"
	.string "フレンドリィショップで かえる!$"

ViridianForest_Text_ContactOakViaPCToRatePokedex::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "パソコンで オーキドはかせに\n"
	.string "ずかんを ひょうか してもらおう!$"

ViridianForest_Text_CantCatchOwnedMons::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "ひとの ポケモンは\n"
	.string "つかまえられない。\p"
	.string "モンスターボールは やせいの\n"
	.string "ポケモンだけに なげよう!$"

ViridianForest_Text_WeakenMonsBeforeCapture::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "ポケモンは よわらせてから\n"
	.string "つかまえよう!\p"
	.string "げんきだと にげられるかも!$"

ViridianForest_Text_LeavingViridianForest::
	.string "{JPN}ここで トキワのもり おわり\n"
	.string "この さき ニビシティ$"

