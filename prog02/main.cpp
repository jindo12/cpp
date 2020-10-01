
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char const * argv[]) {
	
	srand(time(NULL));

	int random = rand() % 7;

	cout << "[‚¨ŒäâÜi—”¶¬j]" << endl;

	switch (random) {
	case 0:
		cout << "‘å‹g" << endl;
		break;
	case 1:
		cout << "’†‹g" << endl;
		break;
	case 2:
		cout << "¬‹g" << endl;
		break;
	case 3:
		cout << "‹g" << endl;
		break;
	case 4:
		cout << "––‹g" << endl;
		break;
	case 5:
		cout << "‹¥" << endl;
		break;
	case 6:
		cout << "‘å‹¥" << endl;
		break;
	default:
		break;

	}

	cout << "--------------------------------" << endl;

	cout << "[ƒRƒ“ƒ}‰‰ŽZŽq]" << endl;
	int a = 5;
	int b = 4;
	int min, max;
	if (a > b)
		min = a, max = b;
	else
		min = b, max = b;
	cout << "min = " << min << " max = " << max << endl;

	cout << "--------------------------------" << endl;

	cout << "[ðŒ‰‰ŽZŽq]" << endl;
	int x = 5;
	int y = 19;
	string ans;
	ans = (x > y) ? "yes" : "no";
	cout << x << ">" << y << "?" << endl;
	cout << ans << endl;

	return 0;
}