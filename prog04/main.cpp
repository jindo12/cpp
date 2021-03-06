#include <climits>
#include <iostream>

#include <iomanip> 

using namespace std;

int main(int argc, char const* argv[]) {


	cout << "【列挙型】" << endl;

	enum animal { Dog, Cat, Monkey, Invalid };
	int type;

	do {
		cout << "(dog...0, cat...1, monkey...2, end...3): ";
		cin >> type;
	} while (type < Dog || type > Invalid);

	if (type != Invalid) {
		animal selected = static_cast<animal>(type);
		switch (selected) {
		case Dog:
			cout << "わんわん" << endl;
		case Cat:
			cout << "にゃー" << endl;
		case Monkey:
			cout << "うきうき" << endl;
		case Invalid:
			break;
		}
	}

	cout << "\n";
	
	//cout << "【繰り返しの制御】" << endl;
	//float sum = 0.0F;
	//cout << fixed << setprecision(6);
	//for (int i = 0; i <= 1000; i++) {
	//	float x = static_cast<float>(i) / 1000;
	//	cout << "x = " << x << "\n";
	//	sum += x;
	//}
	//cout << "合計： " << sum << "\n";

	//cout << "\n";

	cout << "【この処理系の整数型で表現できる値】" << endl;

	cout << "char		   : " << CHAR_MIN  << "~" << CHAR_MAX << endl;
	cout << "signed char	   : " << SCHAR_MIN << "~" << SCHAR_MAX << endl;
	cout << "unsigned char	   : " << 0		    << "~" << UCHAR_MAX << endl;
	cout << "\n";
	cout << "short int	   : " << SHRT_MIN << "~" << SHRT_MAX << endl;
	cout << "int		   : " << INT_MIN  << "~" << INT_MAX  << endl;
	cout << "long int	   : " << LONG_MIN << "~" << LONG_MAX << endl;
	cout << "\n";
	cout << "unsigned short int : " << 0 << "~" << USHRT_MAX << endl;
	cout << "unsigned int	   : " << 0 << "~" << UINT_MAX << endl;
	cout << "unsigned long int  : " << 0 << "~" << ULONG_MAX << endl;

	cout << "\n";



	return 0;
}