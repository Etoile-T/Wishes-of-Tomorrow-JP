ThreeIsland_Mart_Frlg_MapScripts::
	.byte 0

ThreeIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ThreeIsland_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
ThreeIsland_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

ThreeIsland_Mart_EventScript_Picnicker::
	msgbox ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_BugCatcher::
	msgbox ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest, MSGBOX_NPC
	end

ThreeIsland_Mart_EventScript_Youngster::
	msgbox ThreeIsland_Mart_Text_BikersWereAboutToTrashMart, MSGBOX_NPC
	end

ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger::
	.string "{JPN}ほんとうなの?\p"
	.string "タマムシデパートって この みせの\n"
	.string "なんばいも おおきいって$"

ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest::
	.string "{JPN}ときどき ここで くすりを かうの\p"
	.string "でも きのみのもりの きのみで\n"
	.string "ポケモンを かいふくする ひとも おおいわ\p"
	.string "だって きのみは ただだし\n"
	.string "なくならないもの$"

ThreeIsland_Mart_Text_BikersWereAboutToTrashMart::
	.string "{JPN}あの ぼうそうぞく この フレンドリィ\n"
	.string "ショップを あらす ところだったんだ\p"
	.string "でていってくれて ほんとに よかった!$"

