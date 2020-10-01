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

	cout << "現在のカウンタ : " << x.value() << endl;

	cout << "カウントアップ回数 : "; cin >> no;*/

	// xは後置、yは前置
	for (int i = 0; i < no; i++) {
		cout << x++ << " " << ++y << endl;
	}

	cout << "カウントダウン回数 : "; cin >> no;*/

	// xは後置、yは前置
	for (int i = 0; i < no; i++) {
		cout << x-- << " " << --y << endl;
	}

	if (!x) {
		cout << "xは0" << endl;
	}
	else {
		cout << "xは0ではない" << endl;
	}

	int n;
	Boolean a;			// defaultconstructor
	Boolean b = a;		// コピーコンストラクタ
	Boolean c = 100;	// 変換constructor
	Boolean ary[8];		// ary[0] ~ ary[7] : defaultconstructor

	cout << "整数値 : "; cin >> n;
	ary[0] = int_eq(n, 5);
	ary[1] = (n != 3);
	ary[2] = Boolean::False;
	ary[3] = 1000;
	ary[4] = c == Boolean::True;
	

	cout << "aの値：" << int(a) << endl;
	cout << "bの値：" << static_cast<const char*>(b) << endl;

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