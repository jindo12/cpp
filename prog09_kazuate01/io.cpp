#include <iostream>

using namespace std;

extern int max_no;	// �P�Ȃ�錾

// ���͂𑣂�
static void prompt() {
	cout << "0 ~ " << max_no << "�̐� : ";
}

int input() {
	int val;
	do {
		prompt();
		cin >> val;
	} while (val < 0 || val > max_no);
	return val;
}

// ���s�̊m�F
bool confirm_retry() {
	int cont;
	cout << "retry?\n" << "Yes...1/No...0 : "; cin >> cont;
	return static_cast<bool>(cont);
}