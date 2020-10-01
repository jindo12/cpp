#include <string>
#include <iostream>
#include "Account.h"

// using指令
using namespace std;

//class Account {
//
//private:
//	string full_name;	// 名義氏名
//	string number;		// 口座番号
//	long crnt_balance;	// 預金
//
//public:
//	Account(string name, string num, long amnt);
//
//	string name() {	return full_name; }
//	string no() { return number; }
//	
//	long balance() { return crnt_balance; }
//	void deposit(long amnt);
//	void widthdraw(long amnt);
//
//};

// クラス定義の外で定義されたメンバ関数
Account::Account(string name, string num, long amnt) {
	full_name = name;
	number = num;
	crnt_balance = amnt;
}

void Account::deposit(long amnt) { 
	crnt_balance += amnt; 
}

void Account::widthdraw(long amnt) {
	crnt_balance -= amnt;
}

void print_Account(string title, Account* p) {
	cout << title << p->name() << "\" (" << p->no() << ") " << p->balance() << "円\n";
}

int main(int argc, char const* argv[]) {
	
	// ユーザ型定義
	Account suzuki("suzuki ichiro", "294732", 1000);
	Account takeda("takeda hirohumi", "9375958", 200);

	suzuki.widthdraw(200);	// 支出
	takeda.deposit(100);	// 収入

	cout << "◇suzukiの口座 : \"" << suzuki.name() << "\" (" << suzuki.no() << ") " << suzuki.balance() << "円" << endl;
	cout << "◇takedaの口座 : \"" << takeda.name() << "\" (" << takeda.no() << ") " << takeda.balance() << "円" << endl;

	cout << "======================================================" << endl;

	// arrow演算子の利用
	print_Account("◇鈴木君の口座 : ", &suzuki);
	print_Account("◇武田君の口座 : ", &takeda);

	cout << "======================================================" << endl;

	// Car class
	std::string name;
	int width, length, height;
	double gas;

	cout << "input car data." << endl;
	cout << "name : "; cin >> name;
	cout << "width : "; cin >> width;
	cout << "length : "; cin >> length;
	cout << "height : "; cin >> height;
	cout << "fuel : "; cin >> gas;

	Car myCar(name, width, length, height, gas);

	while (true) {
		cout << "現在位置 (" << myCar.x() << ", " << myCar.y() << ")" << endl;
		cout << "残量 : " << myCar.fuel() << endl;
		
		cout << "移動[0...No / 1...Yes] : ";
		int move; cin >> move;

		if (move == 0) break;

		double dx, dy;
		cout << "X方向の移動距離 : "; cin >> dx;
		cout << "Y方向の移動距離 : "; cin >> dy;
		if (!myCar.move(dx, dy)) {
			cout << "燃料が足りません" << endl;
		}
	}

}