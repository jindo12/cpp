#pragma once
#include <string>
#include "Date.h"

class Account
{
	std::string full_name;
	std::string number;
	long crnt_balance;
	Date open;				// 口座開設日

public:
	//Account(std::string name, std::string num, long amnt, int y, int m, int d);
	Account(std::string name, std::string num, long amnt, const Date& op);
	
	void deposit(long amnt);	// 預ける
	void widthdraw(long amnt);	// おろす

	std::string name() const { return full_name; };
	std::string no() const { return number; };
	long balance() const { return crnt_balance; };
	Date opening_date() const { return open; };		// 口座開設日を調べる
};

