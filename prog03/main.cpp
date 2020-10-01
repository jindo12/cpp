#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include <iomanip>

using namespace std;

int main(int argc, char const* argv[]) {

	srand(time(NULL));

	int no = rand() % 100;
	int x;

	// �����Q�[��
	
	cout << "Game Start!!!!" << endl;
	do {
		cout << "�������� : ";
		cin >> x;
		if (x > no) {
			cout << "�����Ə����Ȑ�����B" << endl;
		}
		else if (x < no) {
			cout << "�����Ƒ傫�Ȑ�����B" << endl;
		}
	} while (!(x == no));
	
	cout << "�����ł��B" << endl;
	
	cout << "==============================" << endl;

	// �������ق��̐��ȏ�ŁA�傫���ق��̐��ȉ��̑S�������
	int a, b;
	int diff;
	cout << "2�̐����l����͂��Ă������� :";
	cin >> a >> b;
	if (a > b) {
		diff = a - b;
		for (int i = 0; i <= diff; i++) {
			cout << b << " ";
			b++;
		}
	}
	else {
		diff = b - a;
		for (int i = 0; i <= diff; i++) {
			cout << a << " ";
			a++;
		}
	}

	cout << "\n";

	cout << "==============================" << endl;

	// ���d���[�v�i���j
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << setw(3) << i * j;
		}
		cout << "\n";
	}

	cout << "==============================" << endl;

	// ���p�O�p�`�̕\��
	int n;
	cout << "�����l�����:";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int k = 0; k < n - i; k++) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = n; i <= j; j--) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i+1); j++) {
			cout << " ";
		}
		for (int k = 0; k <= i; k++) {
			cout << "*";
		}
		cout << "\n";
	}


	cout << "\n";

	cout << "==============================" << endl;

	// ���i�s���~�b�h
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i + 1); j++) {
			cout << " ";
		}
		for (int k = 0; k < ((i+1) - 1) * 2 + 1; k++) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "\n";

	// ���i�t�s���~�b�h

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << " ";
		}
		for (int k = 0; k < (n - i) * 2 - 1; k++) {
			cout << i % 10 + 1;
		}
		cout << "\n";
	}

	cout << "==============================" << endl;

	// n�i�̐����`��\������
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << setw(3) << "*";
		}
		cout << "\n";
	}

	cout << "==============================" << endl;

	// ����񂯂�Q�[��

	int you, yFlag = 0;
	int cp, cFlag = 0;
	int retry;
	
	cout << "[�W�����P�����[��]" << endl;
	
	do {
		cp = rand() % 3;
		cout << "(�O�[...0, �`���L...1, �p�[...2):";
		cin >> you;

		switch (you) {
			case 0:
				cout << "you : " << you << ", cp : " << cp << endl;
				break;
			case 1:
				cout << "you : " << you << ", cp : " << cp << endl;
				break;
			case 2:
				cout << "you : " << you << ", cp : " << cp << endl;
				break;
			default:
				break;
		}

		int diff = (you - cp + 3) % 3;

		if (diff == 0) {
			cout << "draw" << endl;
		}
		else if (diff == 1) {
			cout << "u are lose" << endl;
			cFlag++;
		}
		else {
			cout << "u are win" << endl;
			yFlag++;
		}

		if (cFlag == 3 || yFlag == 3) {
			cout << "Result => you: " << yFlag << ", cp: " << cFlag << endl;
			break;
		}

		cout << "retry? (yas...1, no...0):";
		cin >> retry;
	} while (retry == 1);

	cout << "==============================" << endl;

	// ����q�ɂ�鏑���w��
	cout << oct << 1234 << endl; // 8shin
	cout << dec << 1234 << endl; // 10
	cout << hex << 1234 << endl; // 16

	cout << "\n";

	cout << showbase;			 // ��\����t��
	cout << oct << 1234 << endl; // 8shin
	cout << dec << 1234 << endl; // 10
	cout << hex << 1234 << endl; // 16

	cout << "\n";

	cout << setw(10) << internal	<< "abc" << endl;
	cout << setw(10) << left		<< "abc" << endl;
	cout << setw(10) << right		<< "abc" << endl;

	cout << "\n";

	cout << setbase(10);		 // n�i��
	cout << setw(10) << internal	<< "-123" << endl;
	cout << setw(10) << left		<< "-123" << endl;
	cout << setw(10) << right		<< "-123" << endl;

	cout << "\n";

	cout << setfill('*');		 // �l�ߕ����������ɐݒ�
	cout << setw(10) << internal	<< "-123" << endl;
	cout << setw(10) << left		<< "-123" << endl;
	cout << setw(10) << right		<< "-123" << endl;
	cout << setfill(' ');

	cout << "\n";

	// ���������_�����Œ菬���_�L�@
	cout << fixed		<< setw(10) << setprecision(2) << 123.5 << endl;
	// ���������_�����w���t���L�@
	cout << scientific	<< setw(10) << setprecision(2) << 123.5 << endl;

	return 0;
}