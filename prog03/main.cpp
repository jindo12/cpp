#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include <iomanip>

using namespace std;

int main(int argc, char const* argv[]) {

	srand(time(NULL));

	int no = rand() % 100;
	int x;

	// 数当ゲーム
	
	cout << "Game Start!!!!" << endl;
	do {
		cout << "いくつかな : ";
		cin >> x;
		if (x > no) {
			cout << "もっと小さな数だよ。" << endl;
		}
		else if (x < no) {
			cout << "もっと大きな数だよ。" << endl;
		}
	} while (!(x == no));
	
	cout << "正解です。" << endl;
	
	cout << "==============================" << endl;

	// 小さいほうの数以上で、大きいほうの数以下の全整数を列挙
	int a, b;
	int diff;
	cout << "2つの整数値を入力してください :";
	cin >> a >> b;
	if (a > b) {
		diff = a - b;
		for (int i = 0; i <= diff; i++) {
			cout << b << " ";
			b++;
		}
	}
	else {
		diff = b - a;
		for (int i = 0; i <= diff; i++) {
			cout << a << " ";
			a++;
		}
	}

	cout << "\n";

	cout << "==============================" << endl;

	// 多重ループ（九九）
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << setw(3) << i * j;
		}
		cout << "\n";
	}

	cout << "==============================" << endl;

	// 直角三角形の表示
	int n;
	cout << "整数値を入力:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int k = 0; k < n - i; k++) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = n; i <= j; j--) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i+1); j++) {
			cout << " ";
		}
		for (int k = 0; k <= i; k++) {
			cout << "*";
		}
		cout << "\n";
	}


	cout << "\n";

	cout << "==============================" << endl;

	// ｎ段ピラミッド
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i + 1); j++) {
			cout << " ";
		}
		for (int k = 0; k < ((i+1) - 1) * 2 + 1; k++) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	// ｎ段逆ピラミッド

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}
		for (int k = 0; k < (n - i) * 2 - 1; k++) {
			cout << i % 10 + 1;
		}
		cout << "\n";
	}

	cout << "==============================" << endl;

	// n段の正方形を表示する
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << setw(3) << "*";
		}
		cout << "\n";
	}

	cout << "==============================" << endl;

	// じゃんけんゲーム

	int you, yFlag = 0;
	int cp, cFlag = 0;
	int retry;
	
	cout << "[ジャンケンげーむ]" << endl;
	
	do {
		cp = rand() % 3;
		cout << "(グー...0, チョキ...1, パー...2):";
		cin >> you;

		switch (you) {
			case 0:
				cout << "you : " << you << ", cp : " << cp << endl;
				break;
			case 1:
				cout << "you : " << you << ", cp : " << cp << endl;
				break;
			case 2:
				cout << "you : " << you << ", cp : " << cp << endl;
				break;
			default:
				break;
		}

		int diff = (you - cp + 3) % 3;

		if (diff == 0) {
			cout << "draw" << endl;
		}
		else if (diff == 1) {
			cout << "u are lose" << endl;
			cFlag++;
		}
		else {
			cout << "u are win" << endl;
			yFlag++;
		}

		if (cFlag == 3 || yFlag == 3) {
			cout << "Result => you: " << yFlag << ", cp: " << cFlag << endl;
			break;
		}

		cout << "retry? (yas...1, no...0):";
		cin >> retry;
	} while (retry == 1);

	cout << "==============================" << endl;

	// 操作子による書式指定
	cout << oct << 1234 << endl; // 8shin
	cout << dec << 1234 << endl; // 10
	cout << hex << 1234 << endl; // 16

	cout << "\n";

	cout << showbase;			 // 基数表示を付加
	cout << oct << 1234 << endl; // 8shin
	cout << dec << 1234 << endl; // 10
	cout << hex << 1234 << endl; // 16

	cout << "\n";

	cout << setw(10) << internal	<< "abc" << endl;
	cout << setw(10) << left		<< "abc" << endl;
	cout << setw(10) << right		<< "abc" << endl;

	cout << "\n";

	cout << setbase(10);		 // n進数
	cout << setw(10) << internal	<< "-123" << endl;
	cout << setw(10) << left		<< "-123" << endl;
	cout << setw(10) << right		<< "-123" << endl;

	cout << "\n";

	cout << setfill('*');		 // 詰め物文字をｃに設定
	cout << setw(10) << internal	<< "-123" << endl;
	cout << setw(10) << left		<< "-123" << endl;
	cout << setw(10) << right		<< "-123" << endl;
	cout << setfill(' ');

	cout << "\n";

	// 浮動小数点数を固定小数点記法
	cout << fixed		<< setw(10) << setprecision(2) << 123.5 << endl;
	// 浮動小数点数を指数付き記法
	cout << scientific	<< setw(10) << setprecision(2) << 123.5 << endl;

	return 0;
}