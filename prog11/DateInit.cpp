#include <iostream>
#include "Account.h"

using namespace std;

int main(int argc, char const* argv[])
{

	const Date birthday(1963, 11, 18);
	Date day[3];

	cout << "birthday : " << birthday << endl;
	cout << "birthday‚Ì•¶Žš—ñ•\Œ» : \"" << birthday.to_string() << "\"\n";

	for (int i = 0; i < 3; i++) {
		cout << "day[" << i << "]‚Ì•¶Žš—ñ•\Œ» : \"" << day[i].to_string() << "\"\n";
	}

	cout << "==============================" << endl;

	Account suzuki("—é–Ø—²ˆê", "1234423", 1000, Date(2125, 1, 25));
	Account takeda("•“c•¶–ç", "234234", 200, Date(2123, 7, 15));
	string dw[] = { "“ú", "ŒŽ", "‰Î", "…", "–Ø", "‹à", "“y" };

	suzuki.widthdraw(200);
	takeda.deposit(100);

	cout << "suzuki Account" << endl;
	cout << "name = " << suzuki.name() << endl;
	cout << "num = " << suzuki.no() << endl;
	cout << "balance = " << suzuki.balance() << endl;
	cout << "openingDay = " << suzuki.opening_date() << endl;
	cout << " (" << dw[suzuki.opening_date().day_of_week()] << ") " << endl;

	cout << "takeda Account" << endl;
	cout << "name = " << takeda.name() << endl;
	cout << "num = " << takeda.no() << endl;
	cout << "balance = " << takeda.balance() << endl;
	cout << "openingDay = " 
		<< takeda.opening_date().year() << "/"
		<< takeda.opening_date().month() << "/"
		<< takeda.opening_date().day() << endl;

	return 0;
}

