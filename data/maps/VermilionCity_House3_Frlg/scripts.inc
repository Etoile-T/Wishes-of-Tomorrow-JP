VermilionCity_House3_Frlg_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
	.string "{JPN}ポッポに てがみを もたせて\n"
	.string "きたの ヤマブキまで とばすのよ。$"

VermilionCity_House3_Text_Pidgey::
	.string "{JPN}ポッポ: クルックー!$"

VermilionCity_House3_Text_DearPippiLetter::
	.string "{JPN}ピッピちゃんへ\n"
	.string "はやく あいたいわ。\p"
	.string "ヤマブキは ロケットだんの ことで\n"
	.string "たいへん だって きいたわ。\p"
	.string "クチバは だいじょうぶ みたい。$"

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
	.string "{JPN}いろんな ひとと メールを\n"
	.string "こうかん したいの。\p"
	.string "だから ポッポを ユニオンルームに\n"
	.string "いかせて メールを こうかん してるの。$"

