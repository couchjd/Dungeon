#include "LevelMap.h"

LevelMap::LevelMap(SpriteManager* sManager) : 
	_WHITE_TILE(&sManager->sprites["white"], true, "white"),
	_GREY_TILE(&sManager->sprites["grey"], true, "grey"),
	_BLACK_TILE(&sManager->sprites["black"], true, "black"),
   // So far, _BLOCK_TILE is the only tile that cannot be passed through.
   // We should probably add a mutator to allow this value to be changed.
   // This could allow for "secret passage" blocks that look solid but
   // can be passed through.
	_BLOCK_TILE(&sManager->sprites["block"], false, "block"),
	_DOWN_TILE(&sManager->sprites["down"], true, "down"),
	_UP_TILE(&sManager->sprites["up"], true, "up") 
{
	_mapTexture.create(MAP_WIDTH, MAP_HEIGHT);
}

LevelMap::~LevelMap(){
}

void LevelMap::create() {
	for (int y = 0; y < W_STEP; y++) {
		for (int x = 0; x < H_STEP; x++) {
			_dMap[y][x] = getTileType(x, y);
			_dMap[y][x]->setPosition(y * 32, x * 32);
		   // creates the texture that will actually be rendered
			_mapTexture.draw(*_dMap[y][x]);
		}
	}
}

void LevelMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Sprite drawSprite = sf::Sprite(_mapTexture.getTexture());
	int width = drawSprite.getTextureRect().width;
	int height = drawSprite.getTextureRect().height;
   // For some reason, the texture was being drawn upside down. We correct this
   // by inverting the texture before it is drawn to the render target.
	drawSprite.setTextureRect(sf::IntRect(0, height, width, -height));
	target.draw(drawSprite, states);
}

DungeonTile* LevelMap::getTileType(int x, int y) {
	int randNum = rand() % (10 - 0 + 1) + 0;
   // Just provides a black border around the map.
   // This will eventually be removed when the line-of-sight functionality
   // is added-->player cannot see what is on the other side of a _BLOCK_TILE.
	if (x == 0 || y == 0 || x == H_STEP - 1 || y == W_STEP - 1)
		return &_BLACK_TILE;
   // Provides a border around the map. This hard-coded border will be removed
   // once we begin generating non-rectangular maps.
	if (x == 1 || y == 1 || x == H_STEP - 2 || y == W_STEP - 2)
		return &_BLOCK_TILE;
   // Generates alternating tile pattern.
	if ((x + y) % 2 == 0) {
	// Adds some random _BLOCK_TILEs for testing purposes.
		if (randNum == 0)
			return &_BLOCK_TILE;
		else
			return &_WHITE_TILE;
	}
	return &_GREY_TILE;
}