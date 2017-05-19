#include "SLevelMap.h"
#define randVal(min, max) (rand() % (max - min + 1) + min)

SLevelMap::SLevelMap() {
}

SLevelMap::~SLevelMap() {
}

void SLevelMap::create() {
	for(int y = 0; y < H_STEP; y++) {
		for(int x = 0; x < W_STEP; x++) {
			dungeonMap[y][x] = getTileType(x, y);
		}
	}
}

TileType SLevelMap::getTileType(int x, int y) {
	int randNum = randVal(0, 10);
	//Just provides a black border around the map.
	//This will eventually be removed when the line-of-sight functionality
	//is added | player cannot see what is on the other side of a _BLOCK_TILE.
	if(x == 0 || y == 0 || x == H_STEP - 1 || y == W_STEP - 1)
		return BLACK;
	//Provides a border around the map. This hard-coded border will be removed
	//once we begin generating non-rectangular maps.
	if(x == 1 || y == 1 || x == H_STEP - 2 || y == W_STEP - 2)
		return BLOCK;
	//Generates alternating tile pattern.
	if((x + y) % 2 == 0) {
		//Adds some random _BLOCK_TILEs for testing purposes.
		if(randNum == 0)
			return BLOCK;
		else
			return WHITE;
	}
	return GREY;
}