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
	goto_if_set FLAG_SYS_POKEMON_GET, KuivaTown_EventScript_YouGotAPokemon
	msgbox KuivaTown_Text_LovelyOutToday, MSGBOX_DEFAULT
	closemessage
	release
	end

KuivaTown_EventScript_YouGotAPokemon::
	msgbox KuivaTown_Text_YouGotAPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

KuivaTown_Text_PlayersHouse:
	.string "{PLAYER}'s Residence$"

KuivaTown_Text_TownSign:
	.string "Kuiva Town\n"
	.string "The heart of the region.$"

KuivaTown_Text_LovelyOutToday:
	.string "The wind in the desert has slowed.\n"
	.string "Sounds lovely for a little exploration.$"

KuivaTown_Text_YouGotAPokemon:
	.string "So you found a bag with Pokémon inside?\n"
	.string "You are one lucky kiddo.\p"
	.string "Promise me you'll do good with it.$"