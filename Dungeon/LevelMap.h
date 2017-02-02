#ifndef LEVELMAP_H
#define LEVELMAP_H

#include <SFML/Graphics.hpp>
#include "DungeonTile.h"
#include "SpriteManager.h"

#define MAP_HEIGHT 480
#define MAP_WIDTH 640
#define TILE_SIZE 32
#define W_STEP MAP_WIDTH / TILE_SIZE
#define H_STEP MAP_HEIGHT / TILE_SIZE

class LevelMap : public sf::Drawable {
public:
	LevelMap(SpriteManager*);
	~LevelMap();
	void create();
	DungeonTile* _dMap[W_STEP][H_STEP];

private:
	DungeonTile _WHITE_TILE;
	DungeonTile _GREY_TILE;
	DungeonTile _BLACK_TILE;
	DungeonTile _BLOCK_TILE;
	DungeonTile _DOWN_TILE;
	DungeonTile _UP_TILE;

	sf::RenderTexture _mapTexture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	DungeonTile* getTileType(int x, int y);
};

#endif // LEVELMAP_H