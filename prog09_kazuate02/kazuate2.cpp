#include <iostream>
#include "kazuate2.h"

using namespace std;

int max_no = 9;

int main(int argc, char const* argv[]) {

	initialize();
	cout << "数当ゲーム開始！" << endl;

	do {
		gen_no();
		int flag;

		do {
			flag = judge(input());
			if (flag == 1) {
				cout << "もっと小さい" << endl;
			}
			else if (flag == 2) {
				cout << "もっと大きい" << endl;
			}
		} while (flag != 0);
		cout << "正解!!!!" << endl;
	} while (confirm_retry());
}
