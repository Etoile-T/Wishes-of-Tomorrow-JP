LavenderTown_Mart_Frlg_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavenderTown_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
LavenderTown_Mart_Items::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

LavenderTown_Mart_Text_SearchingForStatRaiseItems::
	.string "{JPN}ポケモンの のうりょくを あげる\n"
	.string "どうぐを さがしてるんだ。\p"
	.string "1かいの せんとうの あいだ\n"
	.string "こうかが あるんだよ。\p"
	.string "プラスパワー ディフェンダー スピーダー\n"
	.string "スペシャルアップが ほしいんだ。\p"
	.string "どこで てに はいるか しってる?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
	.string "{JPN}げんきのかけらは かった?\n"
	.string "ひんしの ポケモンが げんきに なるよ!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
	.string "{JPN}ときどき 2にんぐみの トレーナーが\n"
	.string "2ひきの ポケモンで\l"
	.string "しょうぶを しかけてくるの。\p"
	.string "そのときは こっちも 2ひきの\n"
	.string "ポケモンを だして たたかうのよ。$"

LavenderTown_Mart_Text_SoldNuggetFromMountainsFor5000::
	.string "{JPN}この あいだ やまおくで\n"
	.string "きんのたまを ひろい ましてね!\p"
	.string "つかえない しなもの ですが\n"
	.string "うったら なんと 5000円でした$"
