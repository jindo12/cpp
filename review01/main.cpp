#include <iostream>
#include "Template.h"
#include "Account.h"

using namespace std;



int main(int argc, char const* argv[]) {
	
	cout << "������������������������" << endl;
	cout << "        Pointer		 " << endl;
	cout << "������������������������" << endl;

	int a = 234; // �P�Ȃ�int�^
	int b = 345;

	// int�^�I�u�W�F�N�g�ւ̃|�C���^pi = int�^�ϐ��i�I�u�W�F�N�g�ja�̃A�h���X
	int* pi = &a; 
	
	cout << pi << endl; // address
	cout << *pi << endl; // value

	cout << "\n";

	cout << "����������������������������������" << endl;
	cout << "      Use of h files in class	�@ " << endl;
	cout << "����������������������������������" << endl;

	Account ac = Account("suzuki", "02498", 1200);
	
	cout << "name : " << ac.getName() << endl;
	cout << "no : " << ac.getNum() << endl;
	cout << "balance : " << ac.balance() << "$" << endl;

	cout << "\n";

	cout << "������������������������" << endl;
	cout << "        Template        " << endl;
	cout << "������������������������" << endl;
	
	Template t;

	int tmp = t.maxof(a, b);
	cout << tmp << endl;


	

	return 0;

}