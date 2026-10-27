CeladonCity_Restaurant_Frlg_MapScripts::
	.byte 0

CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	giveitem_msg CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan, ITEM_COIN_CASE
	setflag FLAG_GOT_COIN_CASE
	release
	end

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
	.string "{JPN}いらっしゃい!\p"
	.string "ごめんなさい いまは\n"
	.string "きゅうけいちゅう なんです。$"

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
	.string "{JPN}ぼくの ポケモンは よわいから\n"
	.string "よく ドラッグストアに いくんだ。$"

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
	.string "{JPN}ねえ! ゲームコーナーの したに\n"
	.string "ちかしつが あるんだって。$"

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
	.string "{JPN}もぐもぐ…\p"
	.string "あの テーブルの ひと スロットで\n"
	.string "ぜんぶ すっちゃったんだって。$"

CeladonCity_Restaurant_Text_TakeThisImBusted::
	.string "{JPN}さあ! わらえよ!\n"
	.string "すっからかんだ!\p"
	.string "もう スロットは やめだ!\n"
	.string "まじめに いきるぞ!\p"
	.string "ほら!\n"
	.string "これは もう いらないからな!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
	.string "{JPN}{ENG}{PLAYER}{JPN}は おとこから\n"
	.string "コインケースを もらった!$"

CeladonCity_Restaurant_Text_MakeRoomForThis::
	.string "{JPN}これを もつ よゆうを つくれよ!$"

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
	.string "{JPN}いつかは とりかえせると\n"
	.string "ずっと おもってたんだ…$"

