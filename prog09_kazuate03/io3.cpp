#include <iostream>
#include "kazuate3.h"

using namespace std;

static void prompt() {
	cout << "0 ~ " << max_no << "‚Ì”(" << c << "‰ñ–Ú) : ";
}

int input() {

	int val;
	do {
		prompt();
		cin >> val;
	} while (val < 0 || val > max_no);
	return val;
}

bool comfirm_retry() {

	int cont;
	cout << "retry?<Yes...1 / No... 0> : "; cin >> cont;
	return static_cast<bool>(cont);

}


