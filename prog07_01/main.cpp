#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

void sum_mul(int x, int y, int* sum, int* mul); //ポインタ渡し
void reverse(int a[], int n); // 要素数nの配列aの並びを反転する
int maxof(const int a[], int n); // 要素数nの配列aの最大値を返却

// intを要素型とする要素数3の配列　を要素型とする要素数nの配列
// (n行3列の2次元配列）の全構成要素にｖを代入
void fill(int (*a)[3], int n, int v); 

void func(int a[][3]);

int main(int argc, char const* argv[]) {

	int n = 145;
	int x = 123;
	int a, b;
	int array[5] = { 1,2,3,4,5 };
	int array1[4];
	int* p = array;	// pはarray[0]を指す
	int wa = 0, seki = 0;
	int* ptr; // int型オブジェクトへのポインタ型ptr

	const int n1 = 5; // 配列n1の要素数
	int c[n1];

	const int ninzu = 5; // 人数
	int height[ninzu], weight[ninzu]; // 身長体重

	int no;
	int x1[2][3] = { 0 };
	int y[4][3] = { 0 };

	cout << "変数nの値は" << n << endl;
	cout << "nのアドレスは " << &n << endl; // 変数nのポインタを生成

	cout << "=====================================" << endl;

	ptr = &n; // ptrはnを指す

	cout << " ptr : " << ptr << endl;  // 指す先のオブジェクトのアドレス
	cout << "*ptr : " << *ptr << endl; // ptrが指すオブジェクトの型と値

	cout << "=====================================" << endl;

	// 型情報の表示
	cout << "n  : " << typeid(n).name() << endl;
	cout << "&n : " << typeid(&n).name() << endl;
	cout << "p  : " << typeid(ptr).name() << endl;
	cout << "*p : " << typeid(*ptr).name() << endl;

	cout << "=====================================" << endl;

	// ポインタの大きさ	
	cout << "sizeof(int)  : " << sizeof(int) << endl;
	cout << "sizeof(int*) : " << sizeof(int*) << endl;

	cout << "=====================================" << endl;

	// ポインタ渡し
	cout << "整数a : "; cin >> a;
	cout << "整数b : "; cin >> b;

	sum_mul(a, b, &wa, &seki);

	cout << "和は" << wa << endl;
	cout << "積は" << seki << endl;

	cout << "=====================================" << endl;

	// swap関数を、ポインタ渡しによって行う
	cout << "整数a : "; cin >> a;
	cout << "整数b : "; cin >> b;

	swap(a, b);

	cout << "値を入れ替えました" << endl;

	cout << a << endl;
	cout << b << endl;

	cout << "=====================================" << endl;

	// 間接演算子と添え字演算子
	for (int i = 0; i < 5; i++) {
		cout << array + i << endl;
		cout << p + i << endl;
	}

	for (int i = 0; i < 5; i++) {
		cout << *(array + i) << endl;
		cout << *(p + i) << endl;
	}
	
	cout << "=====================================" << endl;

	// 添え字演算子のオペランド
	0[array1] = array1[1] = *(array1 + 2) = *(3 + array1) = 7;

	for (int i = 0; i < 4; i++) {
		cout << array1[i] << endl;
	}

	cout << "=====================================" << endl;

	for (int i = 0; i < n1; i++) {
		cout << "c[" << i << "] : "; cin >> c[i];
	}

	reverse(c, n1); // 配列ｃの要素の並びを反転

	cout << "要素の並びを反転しました。" << endl;

	for (int i = 0; i < n1; i++) {
		cout << "c[" << i << "] : " << c[i] << endl;
	}

	cout << "=====================================" << endl;

	// constポインタ型の仮引数

	cout << ninzu << "人の身長と体重を入力せよ" << endl;
	for (int i = 0; i < ninzu; i++) {
		cout << i + 1 << "番目の身長 : "; cin >> height[i];
		cout << i + 1 << "番目の体重 : "; cin >> weight[i];
	}
	int hmax = maxof(height, ninzu);
	int wmax = maxof(weight, ninzu);

	cout << "身長の最大値 : " << hmax << endl;
	cout << "体重の最大値 : " << wmax << endl;

	cout << "=====================================" << endl;

	// 関数間の多次元配列の受け渡し

	cout << "全構成要素に代入する値 ; "; cin >> no;

	fill(x1, 2, no);	 // ｘ1の全構成要素にnoを代入
	fill(y, 4, no);		 // yの全構成要素にnoを代入

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

	// n行3列の2次元配列を受け取る仮引数の型をtypeid演算子によって表示
	
	cout << "実引数x1の型 : " << typeid(x1).name() << endl;
	func(x1);
	cout << "実引数yの型  : " << typeid(y).name() << endl;
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
	cout << "仮引数aの型 : " << typeid(a).name() << endl;
}