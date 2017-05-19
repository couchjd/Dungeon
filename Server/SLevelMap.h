#ifndef SLEVEL_MAP_H
#define SLEVEL_MAP_H

#include <SFML/System.hpp>
#include <string>

#define MAP_HEIGHT 480
#define MAP_WIDTH 640
#define TILE_SIZE 32
#define W_STEP MAP_WIDTH / TILE_SIZE
#define H_STEP MAP_HEIGHT / TILE_SIZE

enum TileType { BLACK = 0, WHITE = 1, GREY = 2, BLOCK = 3, UP = 4, DOWN = 5 };

struct TileInfo {
	std::string type;
	sf::Vector2f position;
	bool passable;
};

class SLevelMap {



public:
	SLevelMap();
	~SLevelMap();
	void create();


private:
	TileType dungeonMap[H_STEP][W_STEP];
	TileType getTileType(int x, int y);
};

#endif // !SLEVEL_MAP_H