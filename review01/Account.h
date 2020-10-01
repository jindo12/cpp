#pragma once
#include <string>


class Account
{
	std::string full_name;
	std::string number;
	long crnt_balance;

public:
	Account(std::string name, std::string num, long amnt);

	std::string getName() { return full_name; };
	std::string getNum() { return number; };
	long balance() { return crnt_balance; };

	void deposit(long amnt);
	void withdraw(long amnt);
};

