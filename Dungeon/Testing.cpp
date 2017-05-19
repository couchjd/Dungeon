#include "Testing.h"
#include <stdio.h>

void Testing::runTest() {
	unsigned long int testValue = 0;
	char* testString = 0;
	//data.a = 1;
	//data.b = 1.0f;
	//data.c = 1.0;
	//data.d = 'a';
	//data.e = true;
	//data.f = 1;

	int array[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 1, 2, 1, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0 }
	};

	for(int x = 0; x < sizeof(m_testArray)/sizeof(int); x++) {
		printf("%x:\t%08x\n", (m_testArray + x), *(m_testArray + x));
		printf("%x:\t%08x\n", &m_testArray[x], m_testArray[x]);
	}
	
	void* newArray;
	newArray = (int*)malloc(sizeof(m_testArray)*sizeof(int));
	printf("%d\n", sizeof(m_testArray));
	printf("%d\n", sizeof((int*)newArray));
	printf("%d\n", sizeof(data));

	/*
	for(int x = 0; x < 5; x++) {
		for(int y = 0; y < 5; y++) {
			testValue |= array[x][y];
			testValue <<= sizeof(int);
			printf("%x\n", testValue);
		}
	}

	testValue = 1;
	printf("%x\n", testValue);
	testValue = testValue << sizeof(int);
	testValue = testValue | 2;
	printf("%x\n", testValue);
	*/
}
