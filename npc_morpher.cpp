/*
* GOSSIP_ICON_CHAT                = 0      White chat bubble
* GOSSIP_ICON_VENDOR              = 1      Brown bag
* GOSSIP_ICON_TAXI                = 2      Flight
* GOSSIP_ICON_TRAINER             = 3      Book
* GOSSIP_ICON_INTERACT_1          = 4      Interaction wheel
* GOSSIP_ICON_INTERACT_2          = 5      Interaction wheel
* GOSSIP_ICON_MONEY_BAG           = 6      Brown bag with yellow dot
* GOSSIP_ICON_TALK                = 7      White chat bubble with black dots
* GOSSIP_ICON_TABARD              = 8      Tabard
* GOSSIP_ICON_BATTLE              = 9      Two swords
* GOSSIP_ICON_DOT                 = 10     Yellow dot
* GOSSIP_ICON_CHAT_11             = 11,    White chat bubble
* GOSSIP_ICON_CHAT_12             = 12,    White chat bubble
* GOSSIP_ICON_CHAT_13             = 13,    White chat bubble
* GOSSIP_ICON_UNK_14              = 14,    INVALID - DO NOT USE
* GOSSIP_ICON_UNK_15              = 15,    INVALID - DO NOT USE
* GOSSIP_ICON_CHAT_16             = 16,    White chat bubble
* GOSSIP_ICON_CHAT_17             = 17,    White chat bubble
* GOSSIP_ICON_CHAT_18             = 18,    White chat bubble
* GOSSIP_ICON_CHAT_19             = 19,    White chat bubble
* GOSSIP_ICON_CHAT_20             = 20,    White chat bubble
*/

#include "ScriptPCH.h"
#include "Config.h"

#define EMOTE_FUNCTION_OFF "Function Disable!"

enum MenuStructure
{
	MAIN_MENU      		= 1,
	MORPH_MENU     		= 2,
	MORPH_MENU_TWO 		= 3,
	MORPH_MENU_THREE 	= 4,
	SCALE_MENU	   		= 5,
};

enum Actions
{
	// Morph Actions
	ACTION_NAGA_LORD	                 = 10, // Menu One
	ACTION_WORGEN                        = 11,
	ACTION_PANDAREN_MONK                 = 12,
	ACTION_ALGALON                       = 13,
	ACTION_RUARZOG						 = 14,
	ACTION_DEMORPH                       = 15,
	ACTION_UNDEAD_MASKED                 = 16,
	ACTION_SCARY_DWARF                   = 17,
	ACTION_UNDEAD_SHADES                 = 18,
	ACTION_VIKING                        = 19,
	ACTION_MINOTAUR                      = 20,
	ACTION_ARTHAS					 	 = 21,	
	ACTION_GHOST						 = 22, // Menu Two
	ACTION_BROKEN						 = 23,
	ACTION_GHOUL						 = 24,
    ACTION_BIRD_MAN						 = 25,
	ACTION_CAT_MAN						 = 26,
	ACTION_SECTOID_TROLL				 = 27,
	ACTION_SCARY_SKELE					 = 28,
	ACTION_NE_ENCHANTRESS				 = 29,
	ACTION_STONE_OGRE					 = 30,
	ACTION_BE_SORCERESS					 = 32,
	ACTION_GROTESQUE					 = 33,
	ACTION_FEM_CENTAUR					 = 34, // Menu Three
	ACTION_FRANKEN_GHOUL				 = 35,
	ACTION_VOODOO_TROLL					 = 36,
	ACTION_WRAITH_WIZARD				 = 37,
	ACTION_MERLOC						 = 38,
	ACTION_DEMORPH_TWO					 = 39,
	ACTION_DEMORPH_THREE				 = 40,
	// Scaled Actions
	ACTION_SCALE_VRYKUL_DEFAULT			 = 41,
	ACTION_SCALE_ONE					 = 42,
	ACTION_SCALE_TWO					 = 43,
	ACTION_SCALE_THREE					 = 44,
	ACTION_SCALE_FOUR					 = 45,
	ACTION_SCALE_FIVE					 = 46,
	ACTION_SCALE_ALGALON_FIX			 = 47,
	ACTION_PANDA_EMPEROR				 = 48,
	ACTION_MOGU_TITAN					 = 49,
};

enum DisplayId
{
	// Menu One
	DISPLAY_ID_NAGA_LORD              = 13031, // Set Scale 0.55
	DISPLAY_ID_WORGEN                 = 657,   // set Scale 1.25
	DISPLAY_ID_PANDAREN_MONK          = 30414, // set Scale 4
	DISPLAY_ID_ALGALON                = 28641, // Set Scale 0.25
	DISPLAY_ID_RUARZOG				  =	25514, // Set Scale 0.75
	DISPLAY_ID_UNDEAD_MASKED		  =	21752, // set Scale 1
	DISPLAY_ID_SCARY_DWARF			  =	21824, // Set Scale 1.25
	DISPLAY_ID_UNDEAD_SHADES		  =	21959, // set Scale 1
	DISPLAY_ID_VIKING     			  =	21997, // Set Scale 0.75
	DISPLAY_ID_MINOTAUR				  =	22007, // Set Scale 0.80
	DISPLAY_ID_ARTHUS				  =	22235, // Set Scale 1
		
	// Menu Two
	DISPLAY_ID_GHOST				  = 21587, // Set Scale 1
	DISPLAY_ID_BROKEN				  = 21593, // Set Scale 1
	DISPLAY_ID_GHOUL				  = 21628, // Set Scale 0.4	
	DISPLAY_ID_BIRD_MAN				  = 21630, // Set Scale 0.3
	DISPLAY_ID_CAT_MAN				  = 21631, // Set Scale 0.3	
	DISPLAY_ID_SECTOID_TROLL		  = 21633, // Set Scale 0.3
	DISPLAY_ID_SCARY_SKELE			  = 21691, // Set Scale 0.4
	DISPLAY_ID_NE_ENCHANTRESS		  = 21714, // Set Scale 1	
	DISPLAY_ID_STONE_OGRE			  = 21721, // Set Scale 0.14
	DISPLAY_ID_BE_SORCERESS			  = 21746, // Set Scale 1
	DISPLAY_ID_GROTESQUE			  = 22125, // Set Scale 0.5
	
	// Menu Three
	DISPLAY_ID_FEM_CENTAUR			  = 21771, // Set Scale 0.4
	DISPLAY_ID_FRANKEN_GHOUL		  = 21962, // Set Scale 0.3	
	DISPLAY_ID_VOODOO_TROLL			  = 22275, // Set Scale 0.6
	DISPLAY_ID_WRAITH_WIZARD		  = 22358, // Set Scale 0.55
	DISPLAY_ID_MERLOC				  = 22530, // Set Scale 0.5
	DISPLAY_ID_PANDA_EMPEROR		  = 42317, // Set Scale 0.6 
	DISPLAY_ID_MOGU_TITAN			  = 48860, // Set Scale 0.15	
};

class npc_morpher : public CreatureScript
{
public:
	npc_morpher() : CreatureScript("npc_morpher") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->PlayerTalkClass->ClearMenus();

		if (sConfigMgr->GetBoolDefault("Server.Morpher.Enable", true))
		{
			player->PlayerTalkClass->ClearMenus();
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, "Morph Menu One ->", GOSSIP_SENDER_MAIN, MORPH_MENU);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, "Morph Menu Two ->", GOSSIP_SENDER_MAIN, MORPH_MENU_TWO);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, "Morph Menu Three ->", GOSSIP_SENDER_MAIN, MORPH_MENU_THREE);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Scale Menu ->", GOSSIP_SENDER_MAIN, SCALE_MENU);
			player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			return true;
		}
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		switch (action)
		{
		case MORPH_MENU:
			if (sConfigMgr->GetBoolDefault("Permanent.Morph.Menu.Enable", true))
			{
				player->PlayerTalkClass->ClearMenus();
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Naga Lord", GOSSIP_SENDER_MAIN, ACTION_NAGA_LORD);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Worgen", GOSSIP_SENDER_MAIN, ACTION_WORGEN);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Pandaren Monk", GOSSIP_SENDER_MAIN, ACTION_PANDAREN_MONK);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Algalon", GOSSIP_SENDER_MAIN, ACTION_ALGALON);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Boss Ruarzog", GOSSIP_SENDER_MAIN, ACTION_RUARZOG);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Undead Masked", GOSSIP_SENDER_MAIN, ACTION_UNDEAD_MASKED);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Scary Dwarf", GOSSIP_SENDER_MAIN, ACTION_SCARY_DWARF);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Undead Shades", GOSSIP_SENDER_MAIN, ACTION_UNDEAD_SHADES);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Viking", GOSSIP_SENDER_MAIN, ACTION_VIKING);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Minotaur", GOSSIP_SENDER_MAIN, ACTION_MINOTAUR);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Arthus", GOSSIP_SENDER_MAIN, ACTION_ARTHAS);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "[Demorph] Logout for Effect!!!", GOSSIP_SENDER_MAIN, ACTION_DEMORPH);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
				return true;
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
				creature->MonsterTextEmote(EMOTE_FUNCTION_OFF, 0, true);
			}
			break;

		case ACTION_NAGA_LORD:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_NAGA_LORD);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 13031);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.55, 'Naga Lord');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.55f);
			break;

		case ACTION_WORGEN:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_WORGEN);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 657);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 2, 'Worgen');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2);
			break;

		case ACTION_PANDAREN_MONK:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_PANDAREN_MONK);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 30414);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 2, 'Panda');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2);
			break;

		case ACTION_ALGALON:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_ALGALON);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 28641);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.25, 'Algalon');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.25f);
			break;

		case ACTION_RUARZOG:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_RUARZOG);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 25514);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.8, 'Ruarzog');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			break;

		case ACTION_UNDEAD_MASKED:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_UNDEAD_MASKED);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21752);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Undead Masked');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;

		case ACTION_SCARY_DWARF:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_SCARY_DWARF);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21824);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1.25, 'Scary Dwarf');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.25f);
			break;

		case ACTION_UNDEAD_SHADES:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_UNDEAD_SHADES);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21959);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Undead Shades');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;

		case ACTION_VIKING:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_VIKING);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21997);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.75, 'Viking');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.75f);
			break;

		case ACTION_MINOTAUR:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_MINOTAUR);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22007);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.8, 'Minotaur');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			break;

		case ACTION_ARTHAS:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_ARTHUS);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22235);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Arthas');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;
		
		case ACTION_DEMORPH:
			player->CLOSE_GOSSIP_MENU();
			player->DeMorph();
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Player Default');", player->GetGUID());
			}
			break;

		case MORPH_MENU_TWO:
			if (sConfigMgr->GetBoolDefault("Permanent.Morph.MenuTwo.Enable", true))
			{
				player->PlayerTalkClass->ClearMenus();
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Ghost", GOSSIP_SENDER_MAIN, ACTION_GHOST);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Broken", GOSSIP_SENDER_MAIN, ACTION_BROKEN);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Ghoul", GOSSIP_SENDER_MAIN, ACTION_GHOUL);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Bird Man", GOSSIP_SENDER_MAIN, ACTION_BIRD_MAN);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Cat Man", GOSSIP_SENDER_MAIN, ACTION_CAT_MAN);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Sectiod Troll", GOSSIP_SENDER_MAIN, ACTION_SECTOID_TROLL);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Scary Skele", GOSSIP_SENDER_MAIN, ACTION_SCARY_SKELE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Night Elf Enchantress", GOSSIP_SENDER_MAIN, ACTION_NE_ENCHANTRESS);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Stone Ogre", GOSSIP_SENDER_MAIN, ACTION_STONE_OGRE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Blood Elf Sorceress", GOSSIP_SENDER_MAIN, ACTION_BE_SORCERESS);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Grotesque", GOSSIP_SENDER_MAIN, ACTION_GROTESQUE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "[Demorph] Logout for Effect!!!", GOSSIP_SENDER_MAIN, ACTION_DEMORPH_TWO);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
				return true;
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
				creature->MonsterTextEmote(EMOTE_FUNCTION_OFF, 0, true);
			}
			break;
		
		case ACTION_GHOST:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_GHOST);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21587);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Ghost');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;
				
		case ACTION_BROKEN:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_BROKEN);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21593);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Broken');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;
		
		case ACTION_GHOUL:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_GHOUL);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21628);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.4, 'Ghoul');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);
			break;
			
		case ACTION_BIRD_MAN:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_BIRD_MAN);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21630);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.3, 'Bird Man');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.3f);
			break;	
		
		case ACTION_CAT_MAN:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_CAT_MAN);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21631);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.3, 'Cat Man');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.3f);
			break;	
			
		case ACTION_SECTOID_TROLL:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_SECTOID_TROLL);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21633);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.3, 'Sectiod Troll');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.3f);
			break;		
			
		case ACTION_SCARY_SKELE:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_SCARY_SKELE);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21691);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.4, 'Scary Skele');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);
			break;		
		
		case ACTION_NE_ENCHANTRESS:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_NE_ENCHANTRESS);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21714);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'NE Enchantress');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;
		
		case ACTION_STONE_OGRE:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_STONE_OGRE);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21721);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .14, 'Stone Ogre');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, .14f);
			break;
			
		case ACTION_BE_SORCERESS:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_BE_SORCERESS);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21746);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'BE Sorceress');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;	
			
		case ACTION_GROTESQUE:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_GROTESQUE);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22125);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .5, 'Grotesque');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, .5f);
			break;	

		case ACTION_DEMORPH_TWO:
			player->CLOSE_GOSSIP_MENU();
			player->DeMorph();
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Player Default');", player->GetGUID());
			}
			break;			
		
		case MORPH_MENU_THREE:
			if (sConfigMgr->GetBoolDefault("Permanent.Morph.MenuThree.Enable", true))
			{
				player->PlayerTalkClass->ClearMenus();
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Female Centaur", GOSSIP_SENDER_MAIN, ACTION_FEM_CENTAUR);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Franken Ghoul", GOSSIP_SENDER_MAIN, ACTION_FRANKEN_GHOUL);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Voodoo Troll", GOSSIP_SENDER_MAIN, ACTION_VOODOO_TROLL);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Wraith Wizard", GOSSIP_SENDER_MAIN, ACTION_WRAITH_WIZARD);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Merloc", GOSSIP_SENDER_MAIN, ACTION_MERLOC);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Pandaren Emperor", GOSSIP_SENDER_MAIN, ACTION_PANDA_EMPEROR);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_2, "Mogu Titan", GOSSIP_SENDER_MAIN, ACTION_MOGU_TITAN);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "[Demorph] Logout for Effect!!!", GOSSIP_SENDER_MAIN, ACTION_DEMORPH_THREE);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
				return true;
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
				creature->MonsterTextEmote(EMOTE_FUNCTION_OFF, 0, true);
			}
			break;
		
		case ACTION_FEM_CENTAUR:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_FEM_CENTAUR);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21771);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .4, 'Female Centaur');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);
			break;
			
		case ACTION_FRANKEN_GHOUL:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_FRANKEN_GHOUL);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 21962);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .3, 'Franken Ghoul');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.3f);
			break;	
		
		case ACTION_VOODOO_TROLL:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_VOODOO_TROLL);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22275);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .6, 'Voodoo Troll');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.6f);
			break;
		
		case ACTION_WRAITH_WIZARD:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_WRAITH_WIZARD);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22358);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .55, 'Wraith Wizard');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, .55f);
			break;
			
		case ACTION_MERLOC:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_MERLOC);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 22530);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .5, 'Merloc');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
			break;	
			
			case ACTION_PANDA_EMPEROR:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_PANDA_EMPEROR);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 42317);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .6, 'Panda Emperor');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.6f);
			break;	
			
			case ACTION_MOGU_TITAN:
			player->CLOSE_GOSSIP_MENU();
			player->SetDisplayId(DISPLAY_ID_MOGU_TITAN);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_morph` (`guid`, `morph`) VALUES(%u, 48860);", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, .15, 'Mogu Titan');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.15f);
			break;	
		
		case ACTION_DEMORPH_THREE:
			player->CLOSE_GOSSIP_MENU();
			player->DeMorph();
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			{
				CharacterDatabase.PExecute("DELETE FROM `character_morph` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Player Default');", player->GetGUID());
			}
			break;	
		
		case SCALE_MENU:
			if (sConfigMgr->GetBoolDefault("Permanent.Scale.Menu.Enable", true))
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to One", GOSSIP_SENDER_MAIN, ACTION_SCALE_ONE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Two", GOSSIP_SENDER_MAIN, ACTION_SCALE_TWO);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Three", GOSSIP_SENDER_MAIN, ACTION_SCALE_THREE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Four", GOSSIP_SENDER_MAIN, ACTION_SCALE_FOUR);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Set my Scale to Five", GOSSIP_SENDER_MAIN, ACTION_SCALE_FIVE);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Vrykul Default Scale [0.8]", GOSSIP_SENDER_MAIN, ACTION_SCALE_VRYKUL_DEFAULT);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "ALGALON Scale Default [0.25]", GOSSIP_SENDER_MAIN, ACTION_SCALE_ALGALON_FIX);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
				return true;
			}
			else
			{
				player->CLOSE_GOSSIP_MENU();
				creature->MonsterTextEmote(EMOTE_FUNCTION_OFF, 0, true);
			}
			break;

		case ACTION_SCALE_ONE:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 1, 'Scaled One');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 1);
			break;

		case ACTION_SCALE_TWO:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 2, 'Scaled Two');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 2);
			break;

		case ACTION_SCALE_THREE:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 3, 'Scaled Three');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 3);
			break;

		case ACTION_SCALE_FOUR:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 4, 'Scaled Four');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 4);
			break;

		case ACTION_SCALE_FIVE:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 5, 'Scaled Five');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 5);
			break;

		case ACTION_SCALE_VRYKUL_DEFAULT:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.8, 'Vrykul Default');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.8f);
			break;

		case ACTION_SCALE_ALGALON_FIX:
			player->CLOSE_GOSSIP_MENU();
			{
				CharacterDatabase.PExecute("DELETE FROM `character_scale` WHERE guid = %u;", player->GetGUID());
				CharacterDatabase.PExecute("INSERT INTO `character_scale` (`guid`, `scale`, `comment`) VALUES(%u, 0.25, 'Alagon Fix');", player->GetGUID());
			}
			player->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.25f);
			break;

		case MAIN_MENU:
			OnGossipHello(player, creature);
			break;
		}
		return true;
	}
};

void AddSC_npc_morpher()
{
	new npc_morpher();
}
