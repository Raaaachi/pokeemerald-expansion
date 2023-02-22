.set LOCALID_MOM, 1

KuivaTown_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KuivaTown_PlayersHouse_1F_MomState
	map_script MAP_SCRIPT_ON_TRANSITION, KuivaTown_PlayersHouse_1F_TurnMom
	.byte 0

KuivaTown_PlayersHouse_1F_MomState:
	map_script_2 VAR_NEW_GAME_STATE, 0, KuivaTown_PlayersHouse_1F_EventScript_MomNiceOut
	map_script_2 VAR_NEW_GAME_STATE, 1, KuivaTown_PlayersHouse_1F_EventScript_MomGoOnAdventure
	.2byte 0

KuivaTown_PlayersHouse_1F_TurnMom:
	goto_if_eq VAR_NEW_GAME_STATE, 1, KuivaTown_PlayersHouse_1F_EventScript_TurnMom
	end

KuivaTown_PlayersHouse_1F_EventScript_MomNiceOut::
	lockall
	applymovement LOCALID_MOM, Common_Movement_FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, KuivaTown_PlayersHouse_1F_Movement_MomApproach
	waitmovement 0
	msgbox KuivaTown_PlayersHouse_1F_Text_ItsNiceOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, KuivaTown_PlayersHouse_1F_Movement_MomGoBack
	waitmovement 0
	setvar VAR_NEW_GAME_STATE, 2
	releaseall
	end

KuivaTown_PlayersHouse_1F_EventScript_TurnMom::
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT
	end

KuivaTown_PlayersHouse_1F_EventScript_MomGoOnAdventure::
	lockall 
	clearflag FLAG_FORCE_FACE_RIGHT
	delay 8 
	msgbox KuivaTown_PlayersHouse_1F_Text_WhatHappened
	closemessage
	delay 32
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	msgbox KuivaTown_PlayersHouse_1F_Text_CantBelieveThatHappened
	closemessage
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	msgbox KuivaTown_PlayersHouse_1F_Text_TakeThesePokeballs
	closemessage
	giveitem ITEM_POKE_BALL, 10
	msgbox KuivaTown_PlayersHouse_1F_Text_TakeCare
	closemessage
	applymovement LOCALID_MOM, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_NEW_GAME_STATE, 2
	releaseall
	end

KuivaTown_PlayersHouse_1F_Movement_MomApproach:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

KuivaTown_PlayersHouse_1F_Movement_MomGoBack:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

KuivaTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_OBTAINED_POKEMON, PlayersHouse_1F_EventScript_MomHealsParty
	msgbox KuivaTown_PlayersHouse_1F_Text_GoExplore, MSGBOX_DEFAULT
	release
	end

KuivaTown_PlayersHouse_1F_Text_ItsNiceOut:
	.string "{PLAYER}!\p"
	.string "It's nice out today,\n"
	.string "for once…\p"
	.string "You should go explore, get some\n"
	.string "fresh air.\l"
	.string "Just be careful of the deep sand,\l"
	.string "wild Pokémon may attack you.\p"
	.string "Stay safe!$"

KuivaTown_PlayersHouse_1F_Text_GoExplore:
	.string "You should go explore, get some\n"
	.string "fresh air.\l"
	.string "Just be careful of the deep sand,\l"
	.string "wild Pokémon may attack you.\p"
	.string "Stay safe!$"

KuivaTown_PlayersHouse_1F_Text_WhatHappened:
	.string "What's up, dear?$"

KuivaTown_PlayersHouse_1F_Text_CantBelieveThatHappened:
	.string "…Wow.\p"
	.string "I can't believe that happened to you.\n"
	.string "I'm glad you are safe.\p"
	.string "Still… what's a bag with rare Pokémon\n"
	.string "doing out here?\l"
	.string "With a Pokédex too…\p"
	.string "It must belong to Professor ???.\n"
	.string "He lives in ??? Town, but if a bag of\l"
	.string "his is out here, maybe he's traveling.\p"
	.string "If you went on your own journey, maybe\n"
	.string "you'd bump into him.\p"
	.string "In that case, I'll look after the other\n"
	.string "two while you are away.$"

KuivaTown_PlayersHouse_1F_Text_TakeThesePokeballs:
	.string "Oh! There are some empty Poké Balls\n"
	.string "in this bag.\l"
	.string "They should help you while you're out.$"

KuivaTown_PlayersHouse_1F_Text_TakeCare:
	.string "You'll want to go through Split Cave\n"
	.string "to access the rest of the region.\p"
	.string "Bye, {PLAYER}! Enjoy your adventure!$"
