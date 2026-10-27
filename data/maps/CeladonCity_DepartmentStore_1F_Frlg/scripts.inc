CeladonCity_DepartmentStore_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorDescriptions, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_ServiceCounter, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_WelcomeToDeptStore::
	.string "{JPN}いらっしゃいませ!\n"
	.string "タマムシデパートへ ようこそ。\p"
	.string "みぎの あんないばんで うりばを\n"
	.string "ごかくにん ください。$"

CeladonCity_DepartmentStore_1F_Text_FloorDescriptions::
	.string "{JPN}1かい: サービスカウンター\p"
	.string "2かい: トレーナーズ マーケット\p"
	.string "3かい: テレビゲーム ショップ\p"
	.string "4かい: ワイズマン ギフト\p"
	.string "5かい: ドラッグストア\p"
	.string "おくじょう: じどうはんばいき$"

CeladonCity_DepartmentStore_1F_Text_ServiceCounter::
	.string "{JPN}1かい: サービスカウンター$"

