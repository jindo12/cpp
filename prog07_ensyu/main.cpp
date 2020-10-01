#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

void reverse(int x[], const int n);
void func(int i, int x[]);
void swap(int* x, const int n);
int sum_of(const int a[], int n);
void aryrmv(int a[], int n, int idx);
void aryins(int a[], int n, int idx, int x);
void maxline(int a[][5], int m[], int n);

int main(int argc, char const * argv[]) {

	const int n = 5;	// �v�f��	
	int a[n] = { 0 };
	int idx = 0;		// �폜�Y�� 
	int x = 0;			// �������l
	const int a1[n] = { 0 };
	int b[][5] = { {1,2,3,4,5}, {3,1,2,3,1}, {3,4,7,1,9} };
	int m[3] = { 0 };

	// �֐�reverse�̉�����x���z��łȂ��|�C���^�ł��邱�Ƃ��m�F����

	for (int i = 0; i < n; i++) {
		cout << "(������) a[" << i << "] (�^��" << typeid(a).name() << "): "; cin >> a[i];
	}

	reverse(a, n);

	cout << "�z��̒l���t���ɂ��܂����B" << endl;

	for (int i = 0; i < n; i++) {
		func(i, a);
		cout << ", a[" << i << "] : " << a[i] << endl;
	}
	 
	cout << "==========================================" << endl;

	// reverse�ł�2�v�f�̌������A�֐�swap�̌Ăяo���ɂ��s���悤�ύX����
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]"  << "): "; cin >> a[i];
	}

	swap(&a[0], n);

	cout << "�z��̒l�����ւ��܂����B" << endl;

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] : " << a[i] << endl;
	}
	cout << "==========================================" << endl;

	// �v�f��n�̔z��a�̑S�v�f�̍��v�����߂ĕԋp����֐����쐬����
	
	cout << "�z��a1�̑S�v�f�̍��v��" << sum_of(a, n) << endl;

	cout << "==========================================" << endl;

	// �v�f��n�̔z��a����v�fa[idx]���폜����֐�arymv���쐬����
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << "): "; cin >> a[i];
	}
	cout << "\n";
	cout << "���Ԗڂ��폜���܂����H : "; cin >> idx;
	aryrmv(a, n, idx);
	cout << "a[" << idx << "]���폜���܂���" << endl;
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << "): " << a[i] << endl;
	}

	cout << "==========================================" << endl;

	// a[idx]��x��������֐�aryins���쐬����
	
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << ": "; cin >> a[i];
	}

	cout << "\n";
	cout << "�z��a�ɒl��������ꏊ : "; cin >> idx;
	cout << "�������l : "; cin >> x;
	
	aryins(a, n, idx, x);

	cout << "\n";
	cout << "a[" << idx << "]��" << x << "�������܂����B" << endl;
	cout << "\n";

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << ": " << a[i]  << endl;
	}

	cout << "==========================================" << endl;

	// ���s5���int�^2�����z��b�̊e�s�̍ő�l���A
	// �v�f��n��1�����z��m�Ɋi�[����֐�maxline���쐬����

	cout << "sizeof(b) : " << sizeof(b) << endl;
	cout << "sizeof(b[0]) : " << sizeof(b[0]) << endl;
	cout << "sizeof(b[0][0]) : " << sizeof(b[0][0]) << endl;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}

	maxline(b, m, 3);

	for (int i = 0; i < 3; i++) {
		cout << m[i] << " ";
	}

	return 0;
}	


// ---------------------------------------------------------------

void reverse(int x[], const int n) {

	for (int i = 0; i < n / 2; i++) {
		int tmp = x[i];
		x[i] = x[n - i - 1];
		x[n - i - 1] = tmp;
	}
}

void func(int i, int x[]) {
	cout << "(������) x[" << i << "] : " << typeid(x).name();
}

void swap(int* x, const int n) {

	for (int i = 0; i < n / 2; i++) {
		int tmp = x[i];
		x[i] = x[n - i - 1];
		x[n - i - 1] = tmp;
	}
}

int sum_of(const int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

void aryrmv(int a[], int n, int idx) {

	if (idx == n - 1) {
		a[idx] = 0;
	}

	for (int i = 0; i < n - idx - 1; i++) {
		a[idx + i] = a[idx + i + 1];
	}
}

void aryins(int a[], int n, int idx, int x) {
	
	for (int i = n; i >= idx; i--) {
		if (i == idx) {
			a[idx] = x;
			break;
		}
		a[i - 1] = a[i - 2];
	}
}

void maxline(int a[][5], int m[], int n) {

	for (int i = 0; i < 3; i++) {
		m[i] = a[i][0];
		for (int j = 0; j < 5; j++) {
			if (m[i] < a[i][j]) {
				m[i] = a[i][j];
			}
		}
		// cout << max[i] << " ";
	}
}