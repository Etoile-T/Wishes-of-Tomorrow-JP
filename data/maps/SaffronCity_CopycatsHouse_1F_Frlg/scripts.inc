SaffronCity_CopycatsHouse_1F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsMom::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_CopycatsDad::
	msgbox SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_1F_EventScript_Chansey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_1F_Text_Chansey
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_1F_Text_DaughterIsSelfCentered::
	.string "{JPN}うちの むすめは じぶん かって でね。\n"
	.string "ともだちも すくないんですよ。$"

SaffronCity_CopycatsHouse_1F_Text_DaughterLikesToMimicPeople::
	.string "{JPN}うちの むすめは ひとの まねが すきでね。\n"
	.string "ちょっと こまって いるんです。\p"
	.string "そのせいで このあたりでは\n"
	.string "ものまねむすめと よばれてます。$"

SaffronCity_CopycatsHouse_1F_Text_Chansey::
	.string "{JPN}ラッキー: ラッキー!$"

