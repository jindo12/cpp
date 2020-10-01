#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int t = 11; // ファイル有効範囲
int fx = 0; // 静的記憶域期間（0で初期化される） + ファイル有効範囲
const int a_size = 5; // 配列aの要素数

int sign_of(int n); // 引数が負ならば-1, 0であれば0を返す
int min(int a, int b, int c);
int med(int a, int b, int c); // 中央値

void put_stars(int n); // 左下直角三角形を作成
void put_nchar(int n, char c); // 右下直角三角形

string print_season(int s); // 引数で指定された月の季節を表示

bool confirm_retry(); // 続行の確認
int read_print(); // 正の数値であればその値を返却、それ以外は再入力

//void alerts(int n = 3); // デフォルト実引数

void put_square(int n, char c = '*'); // 文字cをｎ個連続表示
void put_rectangle(int h, int w, char c); // h行、文字ｃをw個表示

void swap(int& x, int& y); // 参照渡し

void sort(int& a, int& b, int& c); // 三値のソート

void spend(int& x, int& y, int dy); // ｘ時ｙ分の時刻を、dy分後の時刻へ更新する

void alerts(int n = 3) {
	while (n-- > 0) {
		cout << '\a';
	}
}

void func(); // 静的記憶域期間、自動記憶域期間の性質を持つ変数をインクリメント

int& r(int idx); // a[idx]への参照を返却

int max(int a, int b);
int max(int a, int b, int c);

inline double square(double x);
inline double cube(double x);

#define sqr(x) ((x) * (x)) // 関数形式マクロ

int main(int argc, char const* argv[]) {

	int n,m,h,w;
	int a, b, c;
	int x, y, z, dy;
	
	static int sx = 0;	// 静的記憶域期間（0で初期化される）

	int ax = 0;			// 自動記憶域期間（不定値で初期化される）
	
	cout << "0ならば0返却、負ならば-1" << endl;
	cin >> n;

	cout << sign_of(n) << endl;

	cout << "---------------------------" << endl;

	cout << "最小値 : " << min(4, 2, 1) << endl;

	cout << "---------------------------" << endl;
	
	cout << "中央値 ; " << med(6, 10, 7) << endl;

	cout << "---------------------------" << endl;

	cout << "左下直角三角形を表示します。" << endl;
	cout << "段数は : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		put_stars(i);
		cout << "\n";
	}

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "右下直角三角形を表示します。" << endl;
	cout << "段数は : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		put_nchar(n - i, ' ');
		put_nchar(i, '*');
		cout << "\n";
	}

	cout << "\n";
	cout << "---------------------------" << endl;


	cout << "月を入力してください。" << endl;
	cout << "月 : ";
	cin >> m;

	cout << print_season(m) << endl;

	cout << "---------------------------" << endl;

	//srand(time(NULL));
	//cout << "暗算トレーニング!!\n";

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
	//			if (k == x + y + z) // 正解
	//				break;
	//			cout << "不正解！" << endl;
	//		}
	//		else if (r == 1) {
	//			cout << x << " + " << y << " - " << z << " = ";
	//			cin >> k;
	//			if (k == x + y - z) // 正解
	//				break;
	//			cout << "不正解！" << endl;
	//		}
	//		else if (r == 2) {
	//			cout << x << " - " << y << " + " << z << " = ";
	//			cin >> k;
	//			if (k == x - y + z) // 正解
	//				break;
	//			cout << "不正解！" << endl;
	//		}
	//		else if (r == 3) {
	//			cout << x << " - " << y << " - " << z << " = ";
	//			cin >> k;
	//			if (k == x - y - z) // 正解
	//				break;
	//			cout << "不正解！" << endl;
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

	cout << "デフォルト実引数" << endl;
	
	alerts();
	cout << "警報！\n";

	alerts(5);
	cout << "再び警報！\n";

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "正方形を表示します。\n";
	cout << "一辺は : "; cin >> n;

	put_square(n, '*'); // 一辺nの正方形を*で表示

	cout << "長方形を表示します。\n";
	cout << "高さは : "; cin >> h;
	cout << "横幅は : "; cin >> w;

	put_rectangle(h, w, '*'); // 高さがｈで横幅がｗの長方形を＊で表示

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "変数a : "; cin >> a;
	cout << "変数b : "; cin >> b;

	swap(a, b);

	cout << "2つの変数の値を交換しました。" << endl;
	cout << "変数aの値は" << a << endl;
	cout << "変数bの値は" << b << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "実数a : "; cin >> a;
	cout << "実数b : "; cin >> b;
	cout << "実数c : "; cin >> c;

	sort(a, b, c);

	cout << "昇順に並べ替えました。" << endl;
	cout << a << ' ' << b << " " << c << endl;
	
	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "何時？ : "; cin >> x;
	cout << "何分？ : "; cin >> y;
	cout << "経過時間 : "; cin >> dy;
	cout << "\n";
	spend(x, y, dy);
	cout << x << "時" << y << "分" << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	// x :: y 名前空間ｘ中のｙにアクセスする
	cout << "大域的なｔにアクセス：" << ::t << endl;
	
	cout << "\n";
	cout << "---------------------------" << endl;

	// 記憶域期間
	cout << "ax = " << ax << endl;
	cout << "sx = " << sx << endl;
	cout << "fx = " << fx << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	cout << "fx sx ax" << endl;
	cout << "--------------------" << endl;

	// 静的記憶域期間を持つ変数と自動帰国域期間を持つ変数
	for (int i = 0; i < 8; i++) {
		func();
	}

	cout << "\n";
	cout << "---------------------------" << endl;

	// 参照を返却する関数
	for (int i = 0; i < a_size; i++) {
		// 呼び出し式r(i)はa[i]のalias
		r(i) = i;
	}

	for (int i = 0; i < a_size; i++) {
		cout << "r(" << i << ") = " << r(i) << endl;
	}

	cout << "\n";
	cout << "---------------------------" << endl;

	// 関数の多重定義

	cout << "xの値 : ";
	cin >> x;

	cout << "yの値 : ";
	cin >> y;

	cout << "xとｙの最大値は" << max(x, y) << endl;

	cout << "zの値 : ";
	cin >> z;

	cout << "x, y, zの最大値は" << max(x, y, z) << "です。" << endl;
	
	cout << "\n";
	cout << "---------------------------" << endl;

	// インライン関数の利用
	cout << "xの値 : ";
	cin >> x;

	cout << x << "を2乗すると" << square(x) << endl;
	cout << x << "を3乗すると" << cube(x) << endl;

	cout << "\n";
	cout << "---------------------------" << endl;

	// 関数形式マクロの利用
	cout << "整数を入力してください : "; cin >> n;
	cout << n << "の2乗は" << sqr(n) << endl;
	cout << "実数を入力してください ; "; cin >> x;
	cout << x << "の2乗は" << sqr(x) << endl;

	return 0;
}

//=======================================================
//						関数
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
	for (int i = 1; i <= h; i++) {			// h行
		put_nchar(w, c);					// ｃをｗ個
		cout << "\n";
	}
}
string print_season(int m) {
	if (m == 3 || m == 4 || m == 5) {
		return "春";
	}
	else if (m == 6 || m == 7 || m == 8) {
		return "夏";
	}
	else if (m == 9 || m == 10 || m == 11) {
		return "秋";
	}
	else if (m == 12 || m == 1 || m == 2) {
		return "冬";
	}
	else {
		return "1~12までの数値を入力してください。";
	}
}

bool confirm_retry() {
	int retry;
	do {
		cout << "retry？<Yes...1/No...0> : ";
		cin >> retry;
	} while (retry != 0 && retry != 1);
	return static_cast<bool>(retry); // bool型に静的キャスト
}

int read_print() {
	
	int n;
	cout << "正の整数値 ： ";
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
	static int sx = 0;	// 静的記憶域期間+ブロック有効範囲
	int ax = 0;			// 自動記憶域期間+ブロック有効範囲

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