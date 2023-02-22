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
	goto_if_set FLAG_OBTAINED_POKEMON, KuivaTown_EventScript_BestOfLuck
	msgbox KuivaTown_Text_WindHasSlowed, MSGBOX_DEFAULT
	release
	end

KuivaTown_EventScript_BestOfLuck::
	msgbox KuivaTown_Text_BestOfLuck, MSGBOX_DEFAULT
	release
	end

KuivaTown_EventScript_Girl::
	lock
	faceplayer
	msgbox KuivaTown_Text_BrotherBoring, MSGBOX_DEFAULT
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

KuivaTown_Text_BestOfLuck:
	.string "Off on an adventure, eh?\n"
	.string "Best of luck, {PLAYER}!$"

KuivaTown_Text_BrotherBoring:
	.string "It's so fun to run around and play!\p"
	.string "My brother, on the other hand, sits\n"
	.string "inside and watches TV all day.\p"
	.string "He's so boring!$"

	