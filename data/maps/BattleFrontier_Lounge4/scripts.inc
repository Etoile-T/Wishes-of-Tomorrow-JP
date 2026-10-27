BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "{JPN}つよい トレーナーの インタビュー\n"
	.string "きょうは やって いるかなー?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "{JPN}ここで おいしい レストランでも\n"
	.string "やったら もうかりそうやな$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "{JPN}ふう……\p"
	.string "はげしい たたかいの あとは\n"
	.string "ひといき いれないとな……\p"
	.string "でも いまも さくせんや コンボを\n"
	.string "かんがえるのは やすまないんだ。$"

