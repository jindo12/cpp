#include <iostream>
#include <string>

#include <ctime>
#include <cstdlib> // �����̐���

using namespace std;

int main(int argc, char const * argv[]) {

	int a;
	a = 1;
	int b = 4;

	srand(time(NULL));

	int lucky = rand() % 10;
	cout << "�����̃��b�L�[�i���o�[��" << lucky << "�ł��B\n";
	cout << "2�Ŋ���������" << lucky / 2 << "�ł��B\n";
	cout << "2�Ŋ�������]��" << lucky % 2 << "�ł��B\n";

	// ��u�I�u�W�F�N�g�i�s�ρj
	const double PI = 3.14;
	double r;

	cout << "���a:";
	cin >> r;
	cout << "���a" << r << "�̉~�̖ʐς�" << (PI * r * r) << "�ł��B\n";

	string name;

	cout << "�����O��:";
	cin >> name; // �󔒂͓ǂݔ�΂�
	cout << "\a����" "�ɂ���" << name << "����B\n"; // �󔒗ނ��͂��ޕ������e�����͘A��
	return 0;
}