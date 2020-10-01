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
		cout << "�ϐ�x�̒l��" << x << endl;
	}
	void hello() {
		cout << "����ɂ���" << endl;
	}

	namespace Osaka {
		void print_x() {
			cout << "�ϐ�x�̒l��" << x << "�ł����B" << endl;
		}
		void hello() {
			cout << "���������Ă܂����H" << endl;
		}
	}
}

int main(int argc, char const* argv[]) {

	// ���O���
	cout << "English::x = " << English:: x << endl;
	English::print_x();
	English::hello();

	cout << "-------------------------" << endl;

	cout << "Japanese::x = " << Japanese::x << endl;
	Japanese::print_x();
	Japanese::hello();
	
	cout << "=========================" << endl;

	// using�錾��using�w��

	using Japanese::hello;

	cout << "English::x = " << English::x << endl;
	cout << "Japanese::x = " << Japanese::x << endl;

	English::hello();
	hello();			// �֐��������ŌĂяo����

	cout << "=========================" << endl;

	using Japanese::Osaka::print_x;
	
	print_x();
	Japanese::Osaka::hello();
	return 0;
}