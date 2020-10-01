#include <iostream>
#include <cstring>

using namespace std;

int factorial(int n);
int factorial2(int n);
int gcd(int x, int y);
int maxof(int a, int b);

// �֐��e���v���[�g
template <class Type>
Type maxof(const Type x[], int n){
	Type max = x[0];
	for (int i = 0; i < n; i++) {
		if (x[i] > max) {
			max = x[i];
		}
	}
	return max;
}

// �����I�ȋ��
template <class Type2>
Type2 maxof(Type2 a, Type2 b) {
	return a > b ? a : b;
}

// �����I�ȓ��ꉻ
template <> const char* 
maxof<const char*>(const char* a, const char* b) {
	return strcmp(a, b) > 0 ? a : b;
}

template <class Type3>
Type3 square(Type3 x) {
	return x * x;
}


int main(int argc, char const* argv[]) {
	
	int x;
	int y;

	// �K��l�i�ċA�Ăяo������)
	cout << "�����l : "; cin >> x;
	cout << x << "�̊K���" << factorial(x) << endl;

	cout << "=============================================" << endl;

	// �K��l�i�ċA�Ăяo���Ȃ��j
	cout << "�����l �F"; cin >> x;
	cout << x << "�̊K���" << factorial2(x) << endl;

	cout << "=============================================" << endl;

	// ���[�N���b�h�̌ݏ��@
	cout << "�����l1 �F"; cin >> x;
	cout << "�����l2 �F"; cin >> y;

	cout << "2�̍ő���񐔂�" << gcd(x, y) << endl;

	cout << "=============================================" << endl;

	// �֐��e���v���[�g

	const int isize = 4;
	const int dsize = 5;
	int ix[isize] = { 5, 7, 2, 3 };
	double dx[dsize] = { 6.8, 3.9, 2.2, 9.5 };

	cout << "max_ix : " << maxof(ix, isize) << endl;
	cout << "max_dx : " << maxof(dx, dsize) << endl;

	cout << "=============================================" << endl;

	// �����I�ȋ��

	int a, b;

	cout << "����a : "; cin >> a;
	cout << "����b : "; cin >> b;

	cout << "�傫���̂�" << maxof(a, b) << endl;
	cout << "�傫���̂�" << maxof<int>(a, b) << endl;	// �����I
	cout << "�傫���̂�" << maxof<>(a, b) << endl;		// ��������

	cout << "=============================================" << endl;

	// �����I�ȓ��ꉻ

	char s[64], t[64];

	cout << "����a : "; cin >> a;
	cout << "����b : "; cin >> b;
	cout << "������s : "; cin >> s;
	cout << "������t : "; cin >> t;

	cout << "s��t�ő傫���̂�" << maxof<const char*>(s, t) << endl;
	cout << "s��\"ABC\"�ő傫���̂�" << maxof<const char*>(s, "ABC") << endl;

	cout << "=============================================" << endl;

	// x��2������߂�֐��e���v���[�g���쐬����B

	cout << "x : "; cin >> x;
	cout << x << "��2���" << square<int>(x) << endl;

	return 0;
}


int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int factorial2(int n) {

	int sum = 1;
	while (n > 0) {
		sum *= n;
		n--;
	}
	return sum;
}

int gcd(int x, int y) {

	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

int maxof(int a, int b) {
	return a < b ? a : b;
}