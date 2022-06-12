#include "SpriteManager.h"

SpriteManager::SpriteManager(){
	_spriteSheet.loadFromFile("./res/graphics/dungeon_sheet.png");
	
	//Dungeon Blocks
	sprites.emplace("white",	   sf::Sprite(_spriteSheet, sf::IntRect(0,	0,	32, 32)));
	sprites.emplace("grey",		   sf::Sprite(_spriteSheet, sf::IntRect(32,  0,	32, 32)));
	sprites.emplace("block",	   sf::Sprite(_spriteSheet, sf::IntRect(64,  0,	32, 32)));
	sprites.emplace("up",		   sf::Sprite(_spriteSheet, sf::IntRect(96,  0,	32, 32)));
	sprites.emplace("down",		   sf::Sprite(_spriteSheet, sf::IntRect(128, 0, 32, 32)));
	sprites.emplace("black",	   sf::Sprite(_spriteSheet, sf::IntRect(160, 0, 32, 32)));

	//Player Class Sprites
	sprites.emplace("knight",	   sf::Sprite(_spriteSheet, sf::IntRect(0,	32, 32, 32)));
	sprites.emplace("fighter",	   sf::Sprite(_spriteSheet, sf::IntRect(32,  32, 32, 32)));
	sprites.emplace("wizard",	   sf::Sprite(_spriteSheet, sf::IntRect(64,  32, 32, 32)));
	sprites.emplace("sage",		   sf::Sprite(_spriteSheet, sf::IntRect(96,  32, 32, 32)));
	sprites.emplace("alchy",	   sf::Sprite(_spriteSheet, sf::IntRect(128, 32, 32, 32)));
	sprites.emplace("jeweller",   sf::Sprite(_spriteSheet, sf::IntRect(160, 32, 32, 32)));
	sprites.emplace("jones",	   sf::Sprite(_spriteSheet, sf::IntRect(192, 32, 32, 32)));

	//Enemy Sprites
	sprites.emplace("aligog",	   sf::Sprite(_spriteSheet, sf::IntRect(0,	128, 32, 32)));
	sprites.emplace("g_bat",	   sf::Sprite(_spriteSheet, sf::IntRect(32,  128, 32, 32)));
	sprites.emplace("sethron",	   sf::Sprite(_spriteSheet, sf::IntRect(64,  128, 32, 32)));
	sprites.emplace("caveman",	   sf::Sprite(_spriteSheet, sf::IntRect(96,  128, 32, 32)));
	sprites.emplace("firboleg",   sf::Sprite(_spriteSheet, sf::IntRect(128, 128, 32, 32)));
	sprites.emplace("hund",		   sf::Sprite(_spriteSheet, sf::IntRect(160, 128, 32, 32)));
	sprites.emplace("lizzog",	   sf::Sprite(_spriteSheet, sf::IntRect(192, 128, 32, 32)));
	sprites.emplace("spider",	   sf::Sprite(_spriteSheet, sf::IntRect(224, 128, 32, 32)));

	//Pickup Sprites
	sprites.emplace("food",		   sf::Sprite(_spriteSheet, sf::IntRect(0,   64, 32, 32)));
	sprites.emplace("potion",	   sf::Sprite(_spriteSheet, sf::IntRect(32,  64, 32, 32)));
	sprites.emplace("scroll",	   sf::Sprite(_spriteSheet, sf::IntRect(64,  64, 32, 32)));
	sprites.emplace("lsword",	   sf::Sprite(_spriteSheet, sf::IntRect(96,  64, 32, 32)));
	sprites.emplace("2-hand",	   sf::Sprite(_spriteSheet, sf::IntRect(128, 64, 32, 32)));
	sprites.emplace("dagger",	   sf::Sprite(_spriteSheet, sf::IntRect(160, 64, 32, 32)));
	sprites.emplace("wand",		   sf::Sprite(_spriteSheet, sf::IntRect(192, 64, 32, 32)));
	sprites.emplace("spear",	   sf::Sprite(_spriteSheet, sf::IntRect(224, 64, 32, 32)));
	sprites.emplace("sling",	   sf::Sprite(_spriteSheet, sf::IntRect(256, 64, 32, 32)));
	sprites.emplace("armor",	   sf::Sprite(_spriteSheet, sf::IntRect(288, 64, 32, 32)));
	sprites.emplace("leather",	   sf::Sprite(_spriteSheet, sf::IntRect(320, 64, 32, 32)));
	sprites.emplace("cloak",	   sf::Sprite(_spriteSheet, sf::IntRect(352, 64, 32, 32)));
	sprites.emplace("gem",		   sf::Sprite(_spriteSheet, sf::IntRect(384, 64, 32, 32)));
	sprites.emplace("mace",		   sf::Sprite(_spriteSheet, sf::IntRect(416, 64, 32, 32)));
	sprites.emplace("s_rock",	   sf::Sprite(_spriteSheet, sf::IntRect(448, 64, 32, 32)));
	sprites.emplace("l_rock",	   sf::Sprite(_spriteSheet, sf::IntRect(480, 64, 32, 32)));
	sprites.emplace("glove",	   sf::Sprite(_spriteSheet, sf::IntRect(512, 64, 32, 32)));
	sprites.emplace("shield",	   sf::Sprite(_spriteSheet, sf::IntRect(544, 64, 32, 32)));
}

