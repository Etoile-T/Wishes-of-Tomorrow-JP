HotSpring_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HotSpring_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HotSpring_OnFrame
	.byte 0

@ Any tile flagged MB_CRACKED_FLOOR_HOLE drops the player to the pool center.
HotSpring_OnTransition::
	setholewarp MAP_HOT_SPRING, 15, 13
	end

HotSpring_OnFrame::
	map_script_2 VAR_HOT_SPRING_STATE, 0, HotSpring_EventScript_Act2Opening
	.2byte 0

@ Act 2 opens here: the player comes to in the hot spring with Clarkson's
@ final request still ringing in their ears.
HotSpring_EventScript_Act2Opening::
	lockall
	setvar VAR_HOT_SPRING_STATE, 1
	startquest QUEST_LIFES_WORK
	releaseall
	end

@==============================================================================
@ THE HOT SPRING -- where the player comes to after the summit. The bathers are
@ the dead, the dying, and the dreaming. Eerie, vacant, dreamlike. (Placeholder
@ sprites -- swap for custom zombie/skeleton OW sprites later.)
@==============================================================================

@ A body sprawled at the water's edge -- still talking, somehow.
HotSpring_EventScript_Body::
	lock
	faceplayer
	msgbox HotSpring_Text_Body, MSGBOX_DEFAULT
	release
	end

@ A gaunt woman who watches the steam.
HotSpring_EventScript_Maniac::
	lock
	faceplayer
	msgbox HotSpring_Text_Maniac, MSGBOX_DEFAULT
	release
	end

@ An old bather with vacant eyes.
HotSpring_EventScript_Bather::
	lock
	faceplayer
	msgbox HotSpring_Text_Bather, MSGBOX_DEFAULT
	release
	end

HotSpring_Text_Body:
	.string "{JPN}…あったかい…\p"
	.string "もう すこし ここで やすんでいく。\n"
	.string "もう すこしだけ…\p"
	.string "あなたも つかっていきなよ。 おゆが\n"
	.string "さむさを とってくれる。 なにもかも\l"
	.string "とっていって くれるの。$"

HotSpring_Text_Maniac:
	.string "{JPN}しーっ。 ほかの ひとを おこさないで。\p"
	.string "ねむってる だけ。 いまは みんな\n"
	.string "ねむってる だけなの。\p"
	.string "ゆげが いずみに のまれた\n"
	.string "ひとたちの こえを はこんでくる。\p"
	.string "…きこえない？$"

HotSpring_Text_Bather:
	.string "{JPN}…どこかで あったっけ？\p"
	.string "ゆめの なかかも。 それとも はいが\n"
	.string "ふる まえに。\p"
	.string "どっちが ほんとうの せかいなのか\n"
	.string "もう わからなくなっちゃった。$"
