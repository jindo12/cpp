#include <iostream>

using namespace std;

void fill_zero(int* p, int n); // []を使わない配列要素の走査
int seq_search1(int* a, int n, int key); // 値keyを線形探索
int seq_search2(int* a, int n, int key);
int search_idx(int* a, int* idx, int n, int key);

int main(int argc, char const* argv[]) {
	
	int x[5] = { 1,2,3,4,5 };
	int x_zero = sizeof(x) / sizeof(x[0]); // 配列ｘの要素

	int key, idx;
	int x1[8];
	int x1_size = sizeof(x1) / sizeof(x1[0]);

	int x2[7] = { 0 };
	int idx2[7] = { 0 };
	int x2_size = sizeof(x2) / sizeof(x2[0]);

	// ポインタによる配列要素の走査
	for (int i = 0; i < x_zero; i++) {
		cout << "x[" << i << "] = " << x[i] << endl;
	}

	fill_zero(&x[0], x_zero);

	cout << "全要素に0を代入しました";

	for (int i = 0; i < x_zero; i++) {
		cout << "x[" << i << "] = " << x[i] << endl;
	}

	cout << "=================================" << endl;

	// 線形探索1
	cout << "線形探索その1" << endl;
	for (int i = 0; i < x1_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x1[i];
	}

	cout << "探す値は : ";
	cin >> key;

	if ((idx = seq_search1(x1, x1_size, key)) != -1)
		cout << "その値を持つ要素はx[" << idx << "]" << endl;
	else
		cout << "見つかりませんでした。" << endl;

	cout << "=================================" << endl;

	// 線形探索2
	cout << "線形探索その2" << endl;
	for (int i = 0; i < x1_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x1[i];
	}

	cout << "探す値は : ";
	cin >> key;

	if ((idx = seq_search2(x1, x1_size, key)) != -1) {
		cout << "その値を持つ要素はx[" << idx << "]です" << endl;
	}
	else {
		cout << "見つかりませんでした。" << endl;
	}

	cout << "=================================" << endl;

	// 要素数nの配列a内のkeyと等しい全要素の添え字を
	// 配列idxに格納する関数search_idxを作成せよ
	cout << "探す値と等しい値の添え字を配列idxに格納し、その数を返す。" << endl;
	for (int i = 0; i < x2_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x2[i];
	}

	cout << "探す値は:";
	cin >> key;

	if ((idx = search_idx(x2, idx2, x2_size, key) != -1)) {
		cout << key << "は、" << search_idx(x2, idx2, x2_size, key) << "個あります。" << endl;
	}
	else {
		cout << "見つかりませんでした" << endl;
	}

	cout << "=================================" << endl;

	// 動的記憶域期間
	int* d1 = new int;		// 不定値で初期化
	// int* x = new int(); // 0で初期化
	int* d2 = new int(5);	// 生成：初期化子付き
	cout << "整数："; cin >> *d1;
	cout << "*d1 = " << *d1 << endl;
	cout << "*d2 = " << *d2 << endl;
	delete d1;
	delete d2;

	cout << "=================================" << endl;

	// 配列オブジェクトの動的生成
	int asize;	// 配列要素数
	cout << "要素数 : "; cin >> asize;
	int* a = new int[asize];

	for (int i = 0; i < asize; i++) {
		a[i] = i;
	}

	for (int i = 0; i < asize; i++) {
		cout << "a[" << i << "] = " << a[i] << endl;
	}

	delete[] a;

	cout << "=================================" << endl;

	// オブジェクト生成の失敗と例外処理
	//cout << "要素数30000のdouble型配列を繰り返し生成します。" << endl;
	//while (true) {
	//	try {
	//		double* a = new double[30000];
	//	}
	//	catch (bad_alloc) {
	//		cout << "配列の生成に失敗したので、プログラムを中断します。" << endl;
	//		return 1; // プログラム中断
	//	}
	//}

	//cout << "=================================" << endl;

	// 空のポインタ
	//#define NULL 0

	//cout << "=================================" << endl;

	// voidへのポインタ
	
	int* pi;							// intへのポインタ
	void* pv;							// voidへのポインタ
	cout << "voidへのポインタ" << endl;
	pv = pi;							// キャスト不要	
	// pi = pw;							// エラー：キャストが必要
	pi = reinterpret_cast<int*>(pv);	// ok

	cout << "=================================" << endl;

	

	return 0;
}

void fill_zero(int* p, int n) {

	while (n-- > 0) {
		*p = 0; // 着目要素に0を代入
		p++;	// 次の要素に着目
		// *p++ = 0 （省略形）
	}
}

int seq_search1(int* a, int n, int key) {

	for (int i = 0; i < n; i++) {
		if (*a++ == key) {
			return i;	// 探索成功	
		}
	}
	return -1;		// 探索失敗
}

int seq_search2(int* a, int n, int key) {
	int* p = a;

	while (n-- > 0) {
		if (*p == key) {
			return p - a;
		}
		else {
			p++;
		}
	}
	return -1; 
}

int search_idx(int* a, int* idx, int n, int key) {

	int c = 0;
	for (int i = 0; i < n; i++) {
		if (*a++ == key) {
			idx[i] = a[i];
			c++;
		}
	}

	if (c == 0) {
		return -1;
	}

	return c;
}