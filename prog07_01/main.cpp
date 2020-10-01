#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

void sum_mul(int x, int y, int* sum, int* mul); //�|�C���^�n��
void reverse(int a[], int n); // �v�f��n�̔z��a�̕��т𔽓]����
int maxof(const int a[], int n); // �v�f��n�̔z��a�̍ő�l��ԋp

// int��v�f�^�Ƃ���v�f��3�̔z��@��v�f�^�Ƃ���v�f��n�̔z��
// (n�s3���2�����z��j�̑S�\���v�f�ɂ�����
void fill(int (*a)[3], int n, int v); 

void func(int a[][3]);

int main(int argc, char const* argv[]) {

	int n = 145;
	int x = 123;
	int a, b;
	int array[5] = { 1,2,3,4,5 };
	int array1[4];
	int* p = array;	// p��array[0]���w��
	int wa = 0, seki = 0;
	int* ptr; // int�^�I�u�W�F�N�g�ւ̃|�C���^�^ptr

	const int n1 = 5; // �z��n1�̗v�f��
	int c[n1];

	const int ninzu = 5; // �l��
	int height[ninzu], weight[ninzu]; // �g���̏d

	int no;
	int x1[2][3] = { 0 };
	int y[4][3] = { 0 };

	cout << "�ϐ�n�̒l��" << n << endl;
	cout << "n�̃A�h���X�� " << &n << endl; // �ϐ�n�̃|�C���^�𐶐�

	cout << "=====================================" << endl;

	ptr = &n; // ptr��n���w��

	cout << " ptr : " << ptr << endl;  // �w����̃I�u�W�F�N�g�̃A�h���X
	cout << "*ptr : " << *ptr << endl; // ptr���w���I�u�W�F�N�g�̌^�ƒl

	cout << "=====================================" << endl;

	// �^���̕\��
	cout << "n  : " << typeid(n).name() << endl;
	cout << "&n : " << typeid(&n).name() << endl;
	cout << "p  : " << typeid(ptr).name() << endl;
	cout << "*p : " << typeid(*ptr).name() << endl;

	cout << "=====================================" << endl;

	// �|�C���^�̑傫��	
	cout << "sizeof(int)  : " << sizeof(int) << endl;
	cout << "sizeof(int*) : " << sizeof(int*) << endl;

	cout << "=====================================" << endl;

	// �|�C���^�n��
	cout << "����a : "; cin >> a;
	cout << "����b : "; cin >> b;

	sum_mul(a, b, &wa, &seki);

	cout << "�a��" << wa << endl;
	cout << "�ς�" << seki << endl;

	cout << "=====================================" << endl;

	// swap�֐����A�|�C���^�n���ɂ���čs��
	cout << "����a : "; cin >> a;
	cout << "����b : "; cin >> b;

	swap(a, b);

	cout << "�l�����ւ��܂���" << endl;

	cout << a << endl;
	cout << b << endl;

	cout << "=====================================" << endl;

	// �Ԑډ��Z�q�ƓY�������Z�q
	for (int i = 0; i < 5; i++) {
		cout << array + i << endl;
		cout << p + i << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << *(array + i) << endl;
		cout << *(p + i) << endl;
	}
	
	cout << "=====================================" << endl;

	// �Y�������Z�q�̃I�y�����h
	0[array1] = array1[1] = *(array1 + 2) = *(3 + array1) = 7;

	for (int i = 0; i < 4; i++) {
		cout << array1[i] << endl;
	}

	cout << "=====================================" << endl;

	for (int i = 0; i < n1; i++) {
		cout << "c[" << i << "] : "; cin >> c[i];
	}

	reverse(c, n1); // �z�񂃂̗v�f�̕��т𔽓]

	cout << "�v�f�̕��т𔽓]���܂����B" << endl;

	for (int i = 0; i < n1; i++) {
		cout << "c[" << i << "] : " << c[i] << endl;
	}

	cout << "=====================================" << endl;

	// const�|�C���^�^�̉�����

	cout << ninzu << "�l�̐g���Ƒ̏d����͂���" << endl;
	for (int i = 0; i < ninzu; i++) {
		cout << i + 1 << "�Ԗڂ̐g�� : "; cin >> height[i];
		cout << i + 1 << "�Ԗڂ̑̏d : "; cin >> weight[i];
	}
	int hmax = maxof(height, ninzu);
	int wmax = maxof(weight, ninzu);

	cout << "�g���̍ő�l : " << hmax << endl;
	cout << "�̏d�̍ő�l : " << wmax << endl;

	cout << "=====================================" << endl;

	// �֐��Ԃ̑������z��̎󂯓n��

	cout << "�S�\���v�f�ɑ������l ; "; cin >> no;

	fill(x1, 2, no);	 // ��1�̑S�\���v�f��no����
	fill(y, 4, no);		 // y�̑S�\���v�f��no����

	cout << "--- x ---" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << setw(3) << x1[i][j];
		}
		cout << "\n";
	}
	cout << "--- y ---" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << setw(3) << y[i][j];
		}
		cout << "\n";
	}

	cout << "=====================================" << endl;

	// n�s3���2�����z����󂯎�鉼�����̌^��typeid���Z�q�ɂ���ĕ\��
	
	cout << "������x1�̌^ : " << typeid(x1).name() << endl;
	func(x1);
	cout << "������y�̌^  : " << typeid(y).name() << endl;
	func(y);

	return 0;
}

void sum_mul(int x, int y, int* sum, int* mul) {
	*sum = x + y;
	*mul = x * y;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int a[], int n) {
	for (int i = 0; i < n / 2; i++) {
		int tmp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = tmp;
	}
}

int maxof(const int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

void fill(int (*a)[3], int n, int v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = v;
		}
	}
}

void func(int a[][3]) {
	cout << "������a�̌^ : " << typeid(a).name() << endl;
}