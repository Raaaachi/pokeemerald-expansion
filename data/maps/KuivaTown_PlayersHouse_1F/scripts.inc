.set LOCALID_MOM, 1

KuivaTown_PlayersHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KuivaTown_PlayersHouse_1F_MomState
	.byte 0

KuivaTown_PlayersHouse_1F_MomState:
	map_script_2 VAR_NEW_GAME_STATE, 0, KuivaTown_PlayersHouse_1F_EventScript_MomYoureAwake
	.2byte 0

KuivaTown_PlayersHouse_1F_EventScript_MomYoureAwake::
	lockall
	applymovement LOCALID_MOM, Common_Movement_FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	msgbox KuivaTown_PlayersHouse_1F_Text_YoureAwake, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, KuivaTown_PlayersHouse_1F_Movement_MomApproach
	waitmovement 0
	msgbox KuivaTown_PlayersHouse_1F_Text_DesertIsNiceToday
	closemessage
	applymovement LOCALID_MOM, KuivaTown_PlayersHouse_1F_Movement_MomGoBack
	waitmovement 0
	setvar VAR_NEW_GAME_STATE, 1
	release
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

KuivaTown_PlayersHouse_1F_Text_YoureAwake:
	.string "{PLAYER}!$"

KuivaTown_PlayersHouse_1F_Text_DesertIsNiceToday:
	.string "It's nice out in the desert today,\n"
	.string "for once…\p"
	.string "You should go explore it, get some\n"
	.string "fresh air.\l"
	.string "Just be careful of the deep sand,\l"
	.string "wild Pokémon may attack you.\p"
	.string "Stay safe!$"

