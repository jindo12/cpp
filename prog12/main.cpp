#include <iostream>
#include <typeinfo>
#include "Counter_12.h"
#include "Boolean.h"
#include "Complex.h"

using namespace std;

Boolean int_eq(int x, int y);

int main(int argc, char const* argv[]) {

	int no;
	Counter x;
	Counter y;

	cout << "���݂̃J�E���^ : " << x.value() << endl;

	cout << "�J�E���g�A�b�v�� : "; cin >> no;*/

	// x�͌�u�Ay�͑O�u
	for (int i = 0; i < no; i++) {
		cout << x++ << " " << ++y << endl;
	}

	cout << "�J�E���g�_�E���� : "; cin >> no;*/

	// x�͌�u�Ay�͑O�u
	for (int i = 0; i < no; i++) {
		cout << x-- << " " << --y << endl;
	}

	if (!x) {
		cout << "x��0" << endl;
	}
	else {
		cout << "x��0�ł͂Ȃ�" << endl;
	}

	int n;
	Boolean a;			// defaultconstructor
	Boolean b = a;		// �R�s�[�R���X�g���N�^
	Boolean c = 100;	// �ϊ�constructor
	Boolean ary[8];		// ary[0] ~ ary[7] : defaultconstructor

	cout << "�����l : "; cin >> n;
	ary[0] = int_eq(n, 5);
	ary[1] = (n != 3);
	ary[2] = Boolean::False;
	ary[3] = 1000;
	ary[4] = c == Boolean::True;
	

	cout << "a�̒l�F" << int(a) << endl;
	cout << "b�̒l�F" << static_cast<const char*>(b) << endl;

	for(int i = 0; i < 8; i++) {
		cout << "ary[" << i << "] = " << ary[i] << endl;
	}

	Complex c1, c2, c3;

	c3 = c1 + c2;
	c3 = c1 + 7.5;
	c3 = 7.5 + x;

	


	return 0;
}


Boolean int_eq(int x, int y) {
	return x == y;
}