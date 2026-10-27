CeladonCity_DepartmentStore_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_3F_EventScript_CounterTutor::
	goto EventScript_CounterTutor
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid1::
	msgbox CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid2::
	msgbox CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid3::
	msgbox CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_LittleGirl::
	msgbox CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_SuperNES::
	msgbox CeladonCity_DepartmentStore_3F_Text_ItsSuperNES, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV1::
	msgbox CeladonCity_DepartmentStore_3F_Text_AnRPG, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV2::
	msgbox CeladonCity_DepartmentStore_3F_Text_SportsGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV3::
	msgbox CeladonCity_DepartmentStore_3F_Text_PuzzleGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV4::
	msgbox CeladonCity_DepartmentStore_3F_Text_FightingGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_3F_Text_TVGameShop, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_Poster::
	msgbox CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer::
	.string "{JPN}つかまえた ポケモンには IDナンバーと\n"
	.string "おやが とうろく されるんだ。\p"
	.string "おやとは さいしょに つかまえた\n"
	.string "トレーナーの ことだよ。$"

CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter::
	.string "{JPN}やったぜ!\p"
	.string "ダチが おれの ゴーストと じぶんの\n"
	.string "ガルーラを こうかん してくれるって!$"

CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade::
	.string "{JPN}こい ゴースト!\p"
	.string "おれ ゴーストが だいすきで\n"
	.string "あつめてるんだ!\p"
	.string "あれ?\p"
	.string "こうかん してる あいだに ゴーストが\n"
	.string "ちがう ポケモンに なっちゃった!$"

CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID::
	.string "{JPN}こうかんで もらった ポケモンは\n"
	.string "IDナンバーで みわけられるよ。$"

CeladonCity_DepartmentStore_3F_Text_ItsSuperNES::
	.string "{JPN}スーパーファミコンだ。$"

CeladonCity_DepartmentStore_3F_Text_AnRPG::
	.string "{JPN}RPGだ!\n"
	.string "そんな ひまは ない!$"

CeladonCity_DepartmentStore_3F_Text_SportsGame::
	.string "{JPN}スポーツゲームだ!\n"
	.string "パパが よろこびそう!$"

CeladonCity_DepartmentStore_3F_Text_PuzzleGame::
	.string "{JPN}パズルゲームだ!\n"
	.string "はまりそう!$"

CeladonCity_DepartmentStore_3F_Text_FightingGame::
	.string "{JPN}かくとうゲームだ!\n"
	.string "むずかしそう!$"

CeladonCity_DepartmentStore_3F_Text_TVGameShop::
	.string "{JPN}3かい: テレビゲーム ショップ$"

CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon::
	.string "{JPN}あかと みどり!\n"
	.string "どっちも ポケモンだ!$"

Text_CounterTeach::
	.string "{JPN}あっ どうも!\n"
	.string "やっと ポケモンを クリアしたんだ。\p"
	.string "きみは まだ? じゃあ いい わざを\n"
	.string "おしえて あげようか?\p"
	.string "おしえたいのは\n"
	.string "カウンター って わざだよ。\p"
	.string "ぼくが よりかかってる カウンターとは\n"
	.string "ちがうからね!$"

Text_CounterDeclined::
	.string "{JPN}きょうみ ない? きが かわったら\n"
	.string "また きてね。$"

Text_CounterWhichMon::
	.string "{JPN}どの ポケモンに カウンターを\n"
	.string "おしえようか?$"

Text_CounterTaught::
	.string "{JPN}きみの ポケモンに おしえた\n"
	.string "カウンター つかってる?$"
