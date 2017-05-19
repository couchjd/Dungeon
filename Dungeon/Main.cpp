#include <iostream>
#include "Game.h"

#define BOOLEAN(x) ((x > 0) ? "TRUE" : "FALSE")
#define MIN(x, y) (y ^ ((x ^ y) & -(x < y)))
#define MAX(x, y) (x ^ ((x ^ y) & -(x < y)))

void test();
void signCheck();
void minMax();

int main() {

#ifdef _DEBUG
	test();
#endif

	srand(time(NULL));
	Game game;
	game.Init();
	game.Run();
	game.Shutdown();

	return 0;
}


void test() {
	//signCheck();
	int x = 3;
	int y = 55;

	printf("%d\t\t%d\n", x, y);
	printf("%08x\t%08x\n", x, y);
	printf("%08x\t%d\n", (x^y), (x^y));
	printf("%08x\t%d\n", (x<y), (x<y));

	//minMax();
}

void signCheck() {
	printf("%s\n", BOOLEAN((-9 ^ 9) < 0));
	printf("%s\n", BOOLEAN((9 ^ 9) < 0));
	printf("%s\n", BOOLEAN((-9 ^ -9) < 0));
}

void minMax() {
	printf("MIN: %d\n", MIN(1000, 29));
	printf("MIN: %d\n", MAX(1000, 29));
	printf("MIN: %d\n", MIN(-1000, 29));
	printf("MIN: %d\n", MAX(-1000, 29));
}