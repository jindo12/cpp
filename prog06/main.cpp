#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int t = 11; // �t�@�C���L���͈�
int fx = 0; // �ÓI�L������ԁi0�ŏ����������j + �t�@�C���L���͈�
const int a_size = 5; // �z��a�̗v�f��

int sign_of(int n); // ���������Ȃ��-1, 0�ł����0��Ԃ�
int min(int a, int b, int c);
int med(int a, int b, int c); // �����l

void put_stars(int n); // �������p�O�p�`���쐬
void put_nchar(int n, char c); // �E�����p�O�p�`

string print_season(int s); // �����Ŏw�肳�ꂽ���̋G�߂�\��

bool confirm_retry(); // ���s�̊m�F
int read_print(); // ���̐��l�ł���΂��̒l��ԋp�A����ȊO�͍ē���

//void alerts(int n = 3); // �f�t�H���g������

void put_square(int n, char c = '*'); // ����c�����A���\��
void put_rectangle(int h, int w, char c); // h�s�A��������w�\��

void swap(int& x, int& y); // �Q�Ɠn��

void sort(int& a, int& b, int& c); // �O�l�̃\�[�g

void spend(int& x, int& y, int dy); // ���������̎������Ady����̎����֍X�V����

void alerts(int n = 3) {
	while (n-- > 0) {
		cout << '\a';
	}
}

void func(); // �ÓI�L������ԁA�����L������Ԃ̐��������ϐ����C���N�������g

int& r(int idx); // a[idx]�ւ̎Q�Ƃ�ԋp

int max(int a, int b);
int max(int a, int b, int c);

inline double square(double x);
inline double cube(double x);

#define sqr(x) ((x) * (x)) // �֐��`���}�N��

int main(int argc, char const* argv[]) {

	int n,m,h,w;
	int a, b, c;
	int x, y, z, dy;
	
	static int sx = 0;	// �ÓI�L������ԁi0�ŏ����������j

	int ax = 0;			// �����L������ԁi�s��l�ŏ����������j
	
	cout << "0�Ȃ��0�ԋp�A���Ȃ��-1" << endl;
	cin >> n;

	cout << sign_of(n) << endl;

	cout << "---------------------------" << endl;

	cout << "�ŏ��l : " << min(4, 2, 1) << endl;

	cout << "---------------------------" << endl;
	
	cout << "�����l ; " << med(6, 10, 7) << endl;

	cout << "---------------------------" << endl;

	cout << "�������p�O�p�`��\�����܂��B" << endl;
	cout << "�i���� : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		put_stars(i);
		cout << "\n";
	}

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "�E�����p�O�p�`��\�����܂��B" << endl;
	cout << "�i���� : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		put_nchar(n - i, ' ');
		put_nchar(i, '*');
		cout << "\n";
	}

	cout << "\n";
	cout << "---------------------------" << endl;


	cout << "������͂��Ă��������B" << endl;
	cout << "�� : ";
	cin >> m;

	cout << print_season(m) << endl;

	cout << "---------------------------" << endl;

	//srand(time(NULL));
	//cout << "�ÎZ�g���[�j���O!!\n";

	//do {

	//	int x = rand() % 900 + 100;
	//	int y = rand() % 900 + 100;
	//	int z = rand() % 900 + 100;

	//	while (true) {
	//		int k;
	//		int r = rand() % 4;
	//		if (r == 0) {
	//			cout << x << " + " << y << " + " << z << " = ";
	//			cin >> k;
	//			if (k == x + y + z) // ����
	//				break;
	//			cout << "�s�����I" << endl;
	//		}
	//		else if (r == 1) {
	//			cout << x << " + " << y << " - " << z << " = ";
	//			cin >> k;
	//			if (k == x + y - z) // ����
	//				break;
	//			cout << "�s�����I" << endl;
	//		}
	//		else if (r == 2) {
	//			cout << x << " - " << y << " + " << z << " = ";
	//			cin >> k;
	//			if (k == x - y + z) // ����
	//				break;
	//			cout << "�s�����I" << endl;
	//		}
	//		else if (r == 3) {
	//			cout << x << " - " << y << " - " << z << " = ";
	//			cin >> k;
	//			if (k == x - y - z) // ����
	//				break;
	//			cout << "�s�����I" << endl;
	//		}
	//		
	//	}

	//} while (confirm_retry());

	//cout << "\n";
	//cout << "---------------------------" << endl;

	do {
		int n = read_print();
	} while (n <= 0);

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "�f�t�H���g������" << endl;
	
	alerts();
	cout << "�x��I\n";

	alerts(5);
	cout << "�Ăьx��I\n";

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "�����`��\�����܂��B\n";
	cout << "��ӂ� : "; cin >> n;

	put_square(n, '*'); // ���n�̐����`��*�ŕ\��

	cout << "�����`��\�����܂��B\n";
	cout << "������ : "; cin >> h;
	cout << "������ : "; cin >> w;

	put_rectangle(h, w, '*'); // ���������ŉ��������̒����`�����ŕ\��

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "�ϐ�a : "; cin >> a;
	cout << "�ϐ�b : "; cin >> b;

	swap(a, b);

	cout << "2�̕ϐ��̒l���������܂����B" << endl;
	cout << "�ϐ�a�̒l��" << a << endl;
	cout << "�ϐ�b�̒l��" << b << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "����a : "; cin >> a;
	cout << "����b : "; cin >> b;
	cout << "����c : "; cin >> c;

	sort(a, b, c);

	cout << "�����ɕ��בւ��܂����B" << endl;
	cout << a << ' ' << b << " " << c << endl;
	
	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "�����H : "; cin >> x;
	cout << "�����H : "; cin >> y;
	cout << "�o�ߎ��� : "; cin >> dy;
	cout << "\n";
	spend(x, y, dy);
	cout << x << "��" << y << "��" << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	// x :: y ���O��Ԃ����̂��ɃA�N�Z�X����
	cout << "���I�Ȃ��ɃA�N�Z�X�F" << ::t << endl;
	
	cout << "\n";
	cout << "---------------------------" << endl;

	// �L�������
	cout << "ax = " << ax << endl;
	cout << "sx = " << sx << endl;
	cout << "fx = " << fx << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "fx sx ax" << endl;
	cout << "--------------------" << endl;

	// �ÓI�L������Ԃ����ϐ��Ǝ����A������Ԃ����ϐ�
	for (int i = 0; i < 8; i++) {
		func();
	}

	cout << "\n";
	cout << "---------------------------" << endl;

	// �Q�Ƃ�ԋp����֐�
	for (int i = 0; i < a_size; i++) {
		// �Ăяo����r(i)��a[i]��alias
		r(i) = i;
	}

	for (int i = 0; i < a_size; i++) {
		cout << "r(" << i << ") = " << r(i) << endl;
	}

	cout << "\n";
	cout << "---------------------------" << endl;

	// �֐��̑��d��`

	cout << "x�̒l : ";
	cin >> x;

	cout << "y�̒l : ";
	cin >> y;

	cout << "x�Ƃ��̍ő�l��" << max(x, y) << endl;

	cout << "z�̒l : ";
	cin >> z;

	cout << "x, y, z�̍ő�l��" << max(x, y, z) << "�ł��B" << endl;
	
	cout << "\n";
	cout << "---------------------------" << endl;

	// �C�����C���֐��̗��p
	cout << "x�̒l : ";
	cin >> x;

	cout << x << "��2�悷���" << square(x) << endl;
	cout << x << "��3�悷���" << cube(x) << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	// �֐��`���}�N���̗��p
	cout << "��������͂��Ă������� : "; cin >> n;
	cout << n << "��2���" << sqr(n) << endl;
	cout << "��������͂��Ă������� ; "; cin >> x;
	cout << x << "��2���" << sqr(x) << endl;

	return 0;
}

//=======================================================
//						�֐�
//=======================================================

int sign_of(int n) {
	if (n < 0) {
		return -1;
	}
	else if (n == 0) {
		return 0;
	}
}

int min(int a, int b, int c) {
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}


int med(int a, int b, int c) {

	//if (a > b)
	//	return (a <= c ? a : b > c ? b : c);
	//else
	//	return (b <= c ? b : a > c ? a : c);

	if (a >= b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	return b;

}

void put_stars(int n) {
	while (n-- >= 0)
		cout << "*";
}

void put_nchar(int n, char c) {
	while (n-- >= 0)
		cout << setw(2) << c;
}


void put_square(int n, char c) {
	for (int i = 1; i <= n; i++) {
		put_nchar(n, c);
		cout << "\n";
	}
}

void put_rectangle(int h, int w, char c) {	
	for (int i = 1; i <= h; i++) {			// h�s
		put_nchar(w, c);					// ��������
		cout << "\n";
	}
}
string print_season(int m) {
	if (m == 3 || m == 4 || m == 5) {
		return "�t";
	}
	else if (m == 6 || m == 7 || m == 8) {
		return "��";
	}
	else if (m == 9 || m == 10 || m == 11) {
		return "�H";
	}
	else if (m == 12 || m == 1 || m == 2) {
		return "�~";
	}
	else {
		return "1~12�܂ł̐��l����͂��Ă��������B";
	}
}

bool confirm_retry() {
	int retry;
	do {
		cout << "retry�H<Yes...1/No...0> : ";
		cin >> retry;
	} while (retry != 0 && retry != 1);
	return static_cast<bool>(retry); // bool�^�ɐÓI�L���X�g
}

int read_print() {
	
	int n;
	cout << "���̐����l �F ";
	cin >> n;
	if (n > 0) {
		return n;
	}
	else if (n == 0) {
		read_print();
	}
	else if (n < 0) {
		read_print();
	}

}


void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void sort(int& a, int& b, int& c) {
	if (a > b)
		swap(a, b);
	if (b > c)
		swap(b, c);
	if (a > b)
		swap(a, b);
}

void spend(int& x, int& y, int dy) {
	x *= 60;
	x += y;
	x += dy;
	int tmp = x;
	x /= 60;
	y = tmp % 60;
}

void func() {
	static int sx = 0;	// �ÓI�L�������+�u���b�N�L���͈�
	int ax = 0;			// �����L�������+�u���b�N�L���͈�

	fx++;
	sx++;
	ax++;

	cout << fx << " " << sx << " " << ax << endl;
}

int& r(int idx) {
	static int a[a_size];
	return a[idx];
}

int max(int a, int b) {
	return a > b ? a : b;
}

int max(int a, int b, int c) {
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}

inline double square(double x) {
	x = x * x;
	return x;
}

inline double cube(double x) {
	x = square(x) * x;
	return x;
}