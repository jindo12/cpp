#include <iostream>

using namespace std;

namespace English {

	int x = 1;
	void print_x() {
		cout << "The value of x is " << x << endl;
	}
	void hello() {
		cout << "hello" << endl;
	}

}

namespace Japanese {

	int x = 2;
	void print_x() {
		cout << "変数xの値は" << x << endl;
	}
	void hello() {
		cout << "こんにちは" << endl;
	}

	namespace Osaka {
		void print_x() {
			cout << "変数xの値は" << x << "でっせ。" << endl;
		}
		void hello() {
			cout << "もうかってまっか？" << endl;
		}
	}
}

int main(int argc, char const* argv[]) {

	// 名前空間
	cout << "English::x = " << English:: x << endl;
	English::print_x();
	English::hello();

	cout << "-------------------------" << endl;

	cout << "Japanese::x = " << Japanese::x << endl;
	Japanese::print_x();
	Japanese::hello();
	
	cout << "=========================" << endl;

	// using宣言とusing指令

	using Japanese::hello;

	cout << "English::x = " << English::x << endl;
	cout << "Japanese::x = " << Japanese::x << endl;

	English::hello();
	hello();			// 関数名だけで呼び出せる

	cout << "=========================" << endl;

	using Japanese::Osaka::print_x;
	
	print_x();
	Japanese::Osaka::hello();
	return 0;
}