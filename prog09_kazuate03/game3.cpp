#include <ctime>
#include <iostream>
#include <cstdlib>
#include "kazuate3.h"

using namespace std;

static int ans = 0;
int c = 1;

void initialize() {
	
	srand(time(NULL));
	c = 1;
}

int create_q() {
	return ans = rand() % max_no;
}

int judge(int cand){

	if (cand == ans)
		return 0;
	else if (cand > ans)
		return 1;
	else
		return 2;

}

int gameCount() {
	c++;
	return c;
}

