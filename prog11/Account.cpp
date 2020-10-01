#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

// コンストラクタ初期化子による初期化
Account::Account(string name, string num, long amnt, const Date& op)
	: full_name(name), number(num), crnt_balance(amnt), open(op) {

	//full_name = name;
	//number = num;
	//crnt_balance = amnt;
}

void Account::deposit(long amnt) {
	crnt_balance += amnt;
}

void Account::widthdraw(long amnt) {
	crnt_balance -= amnt;
}