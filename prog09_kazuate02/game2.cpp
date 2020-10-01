#include <ctime>
#include <cstdlib>
#include "kazuate2.h"

using namespace std;

static int ans = 0;

void initialize() {
	srand(time(NULL));
}

void gen_no() {
	ans = rand() % (max_no + 1);
}

int judge(int cand) {
	if (cand == ans) {
		return 0;	// seikai
	}
	else if (cand > ans) {
		return 1;	// ookii
	}
	else {
		return 2;	// tiisai
	}
}