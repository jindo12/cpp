#include <string>
#include <iostream>
#include "Account.h"

// using�w��
using namespace std;

//class Account {
//
//private:
//	string full_name;	// ���`����
//	string number;		// �����ԍ�
//	long crnt_balance;	// �a��
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

// �N���X��`�̊O�Œ�`���ꂽ�����o�֐�
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
	cout << title << p->name() << "\" (" << p->no() << ") " << p->balance() << "�~\n";
}

int main(int argc, char const* argv[]) {
	
	// ���[�U�^��`
	Account suzuki("suzuki ichiro", "294732", 1000);
	Account takeda("takeda hirohumi", "9375958", 200);

	suzuki.widthdraw(200);	// �x�o
	takeda.deposit(100);	// ����

	cout << "��suzuki�̌��� : \"" << suzuki.name() << "\" (" << suzuki.no() << ") " << suzuki.balance() << "�~" << endl;
	cout << "��takeda�̌��� : \"" << takeda.name() << "\" (" << takeda.no() << ") " << takeda.balance() << "�~" << endl;

	cout << "======================================================" << endl;

	// arrow���Z�q�̗��p
	print_Account("����،N�̌��� : ", &suzuki);
	print_Account("�����c�N�̌��� : ", &takeda);

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
		cout << "���݈ʒu (" << myCar.x() << ", " << myCar.y() << ")" << endl;
		cout << "�c�� : " << myCar.fuel() << endl;
		
		cout << "�ړ�[0...No / 1...Yes] : ";
		int move; cin >> move;

		if (move == 0) break;

		double dx, dy;
		cout << "X�����̈ړ����� : "; cin >> dx;
		cout << "Y�����̈ړ����� : "; cin >> dy;
		if (!myCar.move(dx, dy)) {
			cout << "�R��������܂���" << endl;
		}
	}

}