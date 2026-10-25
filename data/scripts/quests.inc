@ ============================================================================
@  QUEST SYSTEM (Pokémon Wishes of Tomorrow)
@  Lightweight, native quest tracking:
@   - One VAR per quest (see include/constants/vars.h):
@       0 = not started, 1..N = active stage, 100 = complete.
@   - On-screen notifications: buffer the quest title into STR_VAR_1, then
@     call one of the Notify helpers below (map-name-popup window + jingle;
@     `special ShowQuestPopup` is implemented in src/map_name_popup.c).
@   - The QUEST LOG key item (register it to SELECT!) lists every quest's
@     title, description and current objective, driven by the quest vars.
@  To add a quest: allocate a VAR, add a QuestLog_ sub below and call it
@  from EventScript_QuestLog, and sprinkle setvar+Notify at story beats.
@ ============================================================================

@ --- Notifications (expect STR_VAR_1 = quest title) ------------------------
@ These pre-date the quest-toast system and are only still used by the Ashlands
@ old man, whose beats run before his quest unlocks its menu entry. They play
@ the SEs quest_toast.c plays (SE_PIN to open or advance, SE_SUCCESS to finish)
@ instead of the item/badge fanfares, which made his quest sound like a pickup
@ and blocked the script while the jingle ran.
Quest_EventScript_NotifyStarted::
	special ShowQuestPopup
	playse SE_PIN
	return

Quest_EventScript_NotifyUpdated::
	special ShowQuestPopup
	playse SE_PIN
	return

Quest_EventScript_NotifyCompleted::
	special ShowQuestPopup
	playse SE_SUCCESS
	return

@ --- The Quest Log (opened by using the QUEST LOG key item) ----------------
EventScript_QuestLog::
	lockall
	setvar VAR_TEMP_9, 0
	call QuestLog_FathersFinalWish
	compare VAR_TEMP_9, 0
	goto_if_eq QuestLog_NoQuests
	releaseall
	end

QuestLog_NoQuests::
	msgbox QuestLog_Text_NoQuests, MSGBOX_DEFAULT
	releaseall
	end

@ ----------------------------------------------------------------------------
@  QUEST: A FATHER'S FINAL WISH (main) -- VAR_QUEST_FATHERS_WISH
@  1: fetch the FENTANYL for the dying old prophet
@  2: his story is told; retrieve the CATALPA BOW from his house
@  3: use the bow beside the National Park gravesite
@  100: complete
@ ----------------------------------------------------------------------------
QuestLog_FathersFinalWish::
	compare VAR_QUEST_FATHERS_WISH, 0
	goto_if_eq QuestLog_FFW_Done
	setvar VAR_TEMP_9, 1
	compare VAR_QUEST_FATHERS_WISH, 100
	goto_if_eq QuestLog_FFW_Complete
	compare VAR_QUEST_FATHERS_WISH, 1
	goto_if_eq QuestLog_FFW_Stage1
	compare VAR_QUEST_FATHERS_WISH, 2
	goto_if_eq QuestLog_FFW_Stage2
	msgbox QuestLog_Text_FFW_Stage3, MSGBOX_DEFAULT
	return

QuestLog_FFW_Stage1::
	msgbox QuestLog_Text_FFW_Stage1, MSGBOX_DEFAULT
	return

QuestLog_FFW_Stage2::
	msgbox QuestLog_Text_FFW_Stage2, MSGBOX_DEFAULT
	return

QuestLog_FFW_Complete::
	msgbox QuestLog_Text_FFW_Complete, MSGBOX_DEFAULT
	return

QuestLog_FFW_Done::
	return

@ --- Text -------------------------------------------------------------------
Quest_Text_FathersFinalWishTitle::
	.string "{JPN}ちちおやの さいごの ねがい$"

QuestLog_Text_NoQuests::
	.string "{JPN}クエストにっし\p"
	.string "すすめている クエストは ない。\p"
	.string "せかいは しばし あなたに なにも\n"
	.string "もとめない。 いまの うちに たのしもう。$"

QuestLog_Text_FFW_Stage1::
	.string "{JPN}クエスト: ちちおやの さいごの ねがい\n"
	.string "ー メインクエスト ー しんこうちゅう\p"
	.string "アッシュランドで しにかけた ろうじんが\n"
	.string "ひとつの ものがたりに しがみついている。\l"
	.string "その むねは はいで ふさがれている。\p"
	.string "もくてき: かれの くすりを さがそう。\n"
	.string "かれが よこたわる ばしょの にしにある\l"
	.string "ふるい ほきゅうようの ボールから\l"
	.string "フェンタニルを とってきて わたそう。$"

QuestLog_Text_FFW_Stage2::
	.string "{JPN}クエスト: ちちおやの さいごの ねがい\n"
	.string "ー メインクエスト ー しんこうちゅう\p"
	.string "ろうよげんしゃの ものがたりは かたられた。\n"
	.string "ひとりの むすこは やまに うばわれ\l"
	.string "ひとりの まごは めんに うばわれた。\l"
	.string "さいごの いきが かれの とびらを ひらいた。\p"
	.string "もくてき: かれの いえの なかから\n"
	.string "そふの かたみ アズサユミを\l"
	.string "とってこよう。$"

QuestLog_Text_FFW_Stage3::
	.string "{JPN}クエスト: ちちおやの さいごの ねがい\n"
	.string "ー メインクエスト ー しんこうちゅう\p"
	.string "アズサユミは や を はなたない。\n"
	.string "その ねいろは かなしみが とざしたものを\l"
	.string "ひらくのだ。\p"
	.string "もくてき: ゆみを みずの むこうの\n"
	.string "しぜんこうえんの はかばへ はこび\l"
	.string "その いしの そばで\l"
	.string "つかおう。$"

QuestLog_Text_FFW_Complete::
	.string "{JPN}クエスト: ちちおやの さいごの ねがい\n"
	.string "ー メインクエスト ー たっせい\p"
	.string "はかの そばで ゆみが うたい\n"
	.string "せかいと せかいの さかいめが\l"
	.string "ひらかれた。\p"
	.string "ちちおやの さいごの ねがいは\n"
	.string "さいごまで はこばれた。$"
