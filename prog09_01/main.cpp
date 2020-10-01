#include <iostream>
#include <cstring>

using namespace std;

int factorial(int n);
int factorial2(int n);
int gcd(int x, int y);
int maxof(int a, int b);

// 関数テンプレート
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

// 明示的な具現化
template <class Type2>
Type2 maxof(Type2 a, Type2 b) {
	return a > b ? a : b;
}

// 明示的な特殊化
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

	// 階乗値（再帰呼び出しあり)
	cout << "整数値 : "; cin >> x;
	cout << x << "の階乗は" << factorial(x) << endl;

	cout << "=============================================" << endl;

	// 階乗値（再帰呼び出しなし）
	cout << "整数値 ："; cin >> x;
	cout << x << "の階乗は" << factorial2(x) << endl;

	cout << "=============================================" << endl;

	// ユークリッドの互除法
	cout << "整数値1 ："; cin >> x;
	cout << "整数値2 ："; cin >> y;

	cout << "2つの最大公約数は" << gcd(x, y) << endl;

	cout << "=============================================" << endl;

	// 関数テンプレート

	const int isize = 4;
	const int dsize = 5;
	int ix[isize] = { 5, 7, 2, 3 };
	double dx[dsize] = { 6.8, 3.9, 2.2, 9.5 };

	cout << "max_ix : " << maxof(ix, isize) << endl;
	cout << "max_dx : " << maxof(dx, dsize) << endl;

	cout << "=============================================" << endl;

	// 明示的な具現化

	int a, b;

	cout << "整数a : "; cin >> a;
	cout << "整数b : "; cin >> b;

	cout << "大きいのは" << maxof(a, b) << endl;
	cout << "大きいのは" << maxof<int>(a, b) << endl;	// 明示的
	cout << "大きいのは" << maxof<>(a, b) << endl;		// 自動判定

	cout << "=============================================" << endl;

	// 明示的な特殊化

	char s[64], t[64];

	cout << "整数a : "; cin >> a;
	cout << "整数b : "; cin >> b;
	cout << "文字列s : "; cin >> s;
	cout << "文字列t : "; cin >> t;

	cout << "sとtで大きいのは" << maxof<const char*>(s, t) << endl;
	cout << "sと\"ABC\"で大きいのは" << maxof<const char*>(s, "ABC") << endl;

	cout << "=============================================" << endl;

	// xの2乗を求める関数テンプレートを作成せよ。

	cout << "x : "; cin >> x;
	cout << x << "の2乗は" << square<int>(x) << endl;

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