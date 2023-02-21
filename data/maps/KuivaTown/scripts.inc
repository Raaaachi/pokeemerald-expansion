KuivaTown_MapScripts::
	.byte 0

KuivaTown_EventScript_PlayersHouseSign::
	msgbox KuivaTown_Text_PlayersHouse, MSGBOX_SIGN
	end

KuivaTown_EventScript_TownSign::
	msgbox KuivaTown_Text_TownSign, MSGBOX_SIGN
	end

KuivaTown_EventScript_OldMan::
	lock
	faceplayer
	msgbox KuivaTown_Text_WindHasSlowed, MSGBOX_DEFAULT
	release
	end

KuivaTown_Text_PlayersHouse:
	.string "{PLAYER}'s Residence$"

KuivaTown_Text_TownSign:
	.string "Kuiva Town\n"
	.string "The heart of the region.$"

KuivaTown_Text_WindHasSlowed:
	.string "The wind in the desert has slowed.\n"
	.string "Sounds lovely for a little exploration!$"

	