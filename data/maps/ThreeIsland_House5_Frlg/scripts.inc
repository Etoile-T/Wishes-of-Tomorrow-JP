ThreeIsland_House5_Frlg_MapScripts::
	.byte 0

ThreeIsland_House5_EventScript_LittleGirl::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_House5_EventScript_LittleGirlLostelleFound
	msgbox ThreeIsland_House5_Text_ImNotLostelle
	release
	end

ThreeIsland_House5_EventScript_LittleGirlLostelleFound::
	msgbox ThreeIsland_House5_Text_IllGoPlayWithLostelle
	release
	end

ThreeIsland_House5_Text_ImNotLostelle::
	.string "{JPN}わたし?\n"
	.string "わたしは ロステルじゃ ないよ\p"
	.string "あの こは たぶん\n"
	.string "きのみのもりに いったと おもう\p"
	.string "おべんとうに つかう きのみを\n"
	.string "とりに いくの$"

ThreeIsland_House5_Text_IllGoPlayWithLostelle::
	.string "{JPN}きょうは ロステルと\n"
	.string "あそぼうかな$"

