#include <iostream>
#include "Account.h"

// yusing directivez
// using namespace std <= NG (because it affects even the files you include.)

Account::Account(std::string name, std::string num, long amnt) {
	std::cout << "yThis is Account Classz" << std::endl;
	full_name = name;
	number = num;
	crnt_balance = amnt;

}

void Account::deposit(long amnt) {
	crnt_balance += amnt;
}

void Account::withdraw(long amnt) {
	crnt_balance -= amnt;
}