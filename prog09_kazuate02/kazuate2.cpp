#include <iostream>
#include "kazuate2.h"

using namespace std;

int max_no = 9;

int main(int argc, char const* argv[]) {

	initialize();
	cout << "�����Q�[���J�n�I" << endl;

	do {
		gen_no();
		int flag;

		do {
			flag = judge(input());
			if (flag == 1) {
				cout << "�����Ə�����" << endl;
			}
			else if (flag == 2) {
				cout << "�����Ƒ傫��" << endl;
			}
		} while (flag != 0);
		cout << "����!!!!" << endl;
	} while (confirm_retry());
}
