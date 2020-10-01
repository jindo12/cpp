#pragma once
#include <string>
#include "Date.h"

class Account
{
	std::string full_name;
	std::string number;
	long crnt_balance;
	Date open;				// ŒûÀŠJİ“ú

public:
	//Account(std::string name, std::string num, long amnt, int y, int m, int d);
	Account(std::string name, std::string num, long amnt, const Date& op);
	
	void deposit(long amnt);	// —a‚¯‚é
	void widthdraw(long amnt);	// ‚¨‚ë‚·

	std::string name() const { return full_name; };
	std::string no() const { return number; };
	long balance() const { return crnt_balance; };
	Date opening_date() const { return open; };		// ŒûÀŠJİ“ú‚ğ’²‚×‚é
};

