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

	const int n = 5;	// 要素数	
	int a[n] = { 0 };
	int idx = 0;		// 削除添字 
	int x = 0;			// 代入する値
	const int a1[n] = { 0 };
	int b[][5] = { {1,2,3,4,5}, {3,1,2,3,1}, {3,4,7,1,9} };
	int m[3] = { 0 };

	// 関数reverseの仮引数xが配列でなくポインタであることを確認せよ

	for (int i = 0; i < n; i++) {
		cout << "(実引数) a[" << i << "] (型は" << typeid(a).name() << "): "; cin >> a[i];
	}

	reverse(a, n);

	cout << "配列の値を逆順にしました。" << endl;

	for (int i = 0; i < n; i++) {
		func(i, a);
		cout << ", a[" << i << "] : " << a[i] << endl;
	}
	 
	cout << "==========================================" << endl;

	// reverseでの2要素の交換を、関数swapの呼び出しにより行うよう変更せよ
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]"  << "): "; cin >> a[i];
	}

	swap(&a[0], n);

	cout << "配列の値を入れ替えました。" << endl;

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] : " << a[i] << endl;
	}
	cout << "==========================================" << endl;

	// 要素数nの配列aの全要素の合計を求めて返却する関数を作成せよ
	
	cout << "配列a1の全要素の合計は" << sum_of(a, n) << endl;

	cout << "==========================================" << endl;

	// 要素数nの配列aから要素a[idx]を削除する関数arymvを作成せよ
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << "): "; cin >> a[i];
	}
	cout << "\n";
	cout << "何番目を削除しますか？ : "; cin >> idx;
	aryrmv(a, n, idx);
	cout << "a[" << idx << "]を削除しました" << endl;
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << "): " << a[i] << endl;
	}

	cout << "==========================================" << endl;

	// a[idx]にxを代入する関数aryinsを作成せよ
	
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << ": "; cin >> a[i];
	}

	cout << "\n";
	cout << "配列aに値を代入する場所 : "; cin >> idx;
	cout << "代入する値 : "; cin >> x;
	
	aryins(a, n, idx, x);

	cout << "\n";
	cout << "a[" << idx << "]に" << x << "を代入しました。" << endl;
	cout << "\n";

	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]" << ": " << a[i]  << endl;
	}

	cout << "==========================================" << endl;

	// ｎ行5列のint型2次元配列bの各行の最大値を、
	// 要素数nの1次元配列mに格納する関数maxlineを作成せよ

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
	cout << "(仮引数) x[" << i << "] : " << typeid(x).name();
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