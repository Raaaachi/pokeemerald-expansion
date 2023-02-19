KuivaTown_PlayersHouse_2F_MapScripts::
	.byte 0

KuivaTown_PlayersHouse_2F_EventScript_CheckPlayersPC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end