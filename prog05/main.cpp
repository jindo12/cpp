#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <typeinfo>


using namespace std;

int GetRandom(int min, int max);

int main(int argc, char const* argv[]) {

	srand(time(NULL));

	int a[] = { 1, 2, 3, 4, 5 };
	int a_size = sizeof(a) / sizeof(a[0]); // 配列aの要素数

	const int m = 5; // 定置オブジェクト
	const int m1 = 6;
	const int m2 = 15;
	int score[m];
	int array1[m], c1 = 0;
	float array2[m];
	int array3[m1];
	int array4[m2];
	int b = 0;
	int sum = 0;

	// 1~5列挙
	for (int i = 0; i < a_size; i++) {
		cout << a[i] << endl;
	}

	cout << "=============================" << endl;

	cout << m << "人の点数の合計点と平均点をもとめる" << endl;

	for (int i = 0; i < m; i++) {
		cout << i + 1 << "番の点数 : ";
		cin >> score[i];
		sum += score[i];
	}

	cout << "sum : " << sum << endl;
	cout << "ave : " << static_cast<double>(sum) / m << endl;

	cout << "==============================" << endl;

	cout << "要素数5の配列の要素に対して、先頭から順に54321を代入して表示す" << endl;

	for (int i = 5; i > 0; i--) {
		array1[c1] = i;
		cout << array1[c1] << endl;
		c1++;
		
	}

	cout << "==============================" << endl;

	cout << "浮動小数点型doubleで要素数が5の全要素に対して0.0を代入して表示" << endl;

	// 小数点以下の長さを指定
	cout << fixed << setprecision(1);
	for (int i = 0; i < 5; i++) {
		array2[i] = 0.0F;
		cout << array2[i] << endl;
	}

	cout << "==============================" << endl;

	cout << "要素型がint, 要素数6の配列の全要素を１～１０の乱数で埋め尽くす" << endl;

	for (int i = 0; i < 6; i++) {
		int random = rand() % 10 + 1;
		array3[i] = random;
		cout << array3[i] << endl;
	}

	cout << "==============================" << endl;

	cout << "連続する要素が同じ値とならないように、乱数生成する" << endl;
	for (int i = 0; i < 6; i++) {
		int random = rand() % 10 + 1;
		array3[i] = random;
		cout << array3[i] << endl;
	}

	for (int i = m1; i > 1; i--) {
		int random = rand() % 10 + 1;
		if (array3[i - 2] == array3[i - 1]) {
			cout << "\n";
			cout << i - 2 << "番目:" << array3[i - 2] << " == " << i - 1 << "番目:" << array3[i - 1] << endl;
			array3[i - 1] = random;
			cout << "\n";
		}
		
	}

	cout << "\n";

	for (int i = 0; i < 6; i++) {
		cout << array3[i] << endl;
	}

	cout << "==============================" << endl;

	

	// 配列に0~10の乱数を代入

	for (int i = 0; i < m2; i++) {
		int random = GetRandom(0, 10);
		array4[i] = random;
		cout << array4[i] << " ";
	}
	
	cout << "\n";

	for (int i = 0; i < m2; i++) {
		cout  << "a[" << setw(2) << i << "] : ";
		for (int j = 0; j < array4[i]; j++) {
			 cout << '*';
		}
		cout << "\n";
	}

	cout << "==============================" << endl;

	for (int i = 0; i < m2; i++) {
		int r = GetRandom(0, 10);
		array4[i] = r;
		cout << array4[i] << " ";
	}

	cout << "\n";

	int bmax = array4[0];

	for (int i = 0; i < m2; i++) {
		if (bmax < array4[i]) {
			bmax = array4[i];
		}
	}
	cout << "max = " << bmax << endl;

	for (int i = bmax; i; i--){
		for (int j = 0; j < m2; j++) {
			// 要素の値が最大値以上の場合、*を出力
			if (i <= array4[j]) cout << setw(2) << "*";
			else cout << setw(2) << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < m2; i++) {
		cout << setw(2) << "-";
	}

	cout << "\n";

	for (int i = 0; i < m2; i++) {
		cout << setw(2) << i % 10;
	}

	cout << "\n";
	cout << "==============================" << endl;


	cout << "【配列反転】" << endl;

	int head = 0;
	int tail = 0;
	int center = 0;

	// 反転前
	for (int i = 0; i < m2; i++) {
		int r = GetRandom(0, 10);
		array4[i] = r;
		cout << "a[" << i << "] = " << array4[i] << endl;
	}
	
	cout << "\n";
	
	for (int i = 0; i < m2 / 2; i++) {
		int tmp = array4[i];
		array4[i] = array4[m2 - i - 1];
		array4[m2 - i - 1] = tmp;
	}

	// 反転後
	for (int i = 0; i < m2; i++) {
		cout << "a[" << i << "] = " << array4[i] << endl;
	}

	cout << "\n";
	cout << "==============================" << endl;

	// 配列の要素をの並びをシャッフル
	cout << "シャッフル" << endl;
	for (int i = 0; i < m2; i++) {
		int r = GetRandom(0, 10);
		array4[i] = r;
		cout << "a[" << i << "] = " << array4[i] << endl;
	}
	cout << "\n";
	
	for (int i = 0; i < m2; i++) {
		int shuffle = GetRandom(0, 10);
		array4[i] = array4[shuffle];
		cout << "a[" << i << "] = " << array4[i] << endl;
	}

	cout << "\n";
	cout << "==============================" << endl;

	cout << "配列のコピー" << endl;
	
	const int n = 5;
	int d[n];							// コピー元
	int e[n] = { 0 };					// コピー先

	// 配列に値を読み込む
	for (int i = 0; i < n; i++) {
		cout << "d[" << i << "] : ";
		cin >> d[i];
	}

	// 配列dの全要素を配列にコピー
	for (int i = 0; i < n; i++) {
		e[i] = d[i];
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << "e[" << i << "] = " << e[i] << "\n";
	}

	cout << "\n";
	cout << "==============================" << endl;

	cout << "多次元配列" << endl;

	int array5[3][2];

	cout << "各構成要素の値を代入せよ。" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "a[" << i << "][" << j << "] : ";
			cin >> array5[i][j];
		}
	}
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "a[" << i << "][" << j << "] : " << array5[i][j] << endl;
		}
	}
	
	cout << "\n";
	cout << "==============================" << endl;


	int f[4][3] = { 0 };
	int g[3][4] = { 0 };
	int h[3][3] = { 0 };

	for (int i = 0; i < 4; i++) {
		cout << "(4行・3列), 値を代入せよ。" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "f[" << i << "][" << j << "] : ";
			cin >> f[i][j];
		}
	}
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		cout << "(3行・4列), 値を代入せよ。" << endl;
		for (int j = 0; j < 4; j++) {
			cout << "g[" << i << "][" << j << "] : ";
			cin >> g[i][j];
		}
	}
	cout << "\n";

	// 行列の積
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			h[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				h[i][j] = f[i][k] * g[k][i];
			}
		}
	}

	cout << "\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << setw(3) << h[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "==============================" << endl;

	// 6人の2科目（国語・数学）の点数を読み込む
	int sub[6][2] = { 0 };
	int s[6] = { 0 }; // 学生ごとの合計
	int sum1 = 0; // 国語
	int sum2 = 0; // 数学


	for (int i = 0; i < 6; i++) {
		cout << "国語・数学 : ";
		for (int j = 0; j < 2; j++) {
			cin >> sub[i][j];
			if (j == 0) {
				sum1 += sub[i][j];
			}
			if (i == 1) {
				sum2 += sub[i][j];
			}
			s[i] += sub[i][j];
			
		}
		cout << "s[" << i << "] さんの合計点 ; " << s[i] << "点, 平均点:" << s[i]/2  << "点" << endl;
	}
	
	cout << "-----------------------------------------------" << endl;
	cout << "<国語> (合計点）: " << setw(3) << sum1 <<  ", (平均点）: " << setw(3) << sum1/6 << endl;
	cout << "<数学>（合計点）: " << setw(3) << sum2 <<  ", (平均点）: " << setw(3) << sum2/6 << endl;

	cout << "\n";
	cout << "==============================" << endl;

	cout << "配列subは" << sizeof(sub) / sizeof(sub[0]) << "行"
		<< sizeof(sub[0]) / sizeof(sub[0][0]) << "列です。" << endl;
	cout << "構成要素は" << sizeof(sub) / sizeof(sub[0][0]) << "個です。" << endl;
	cout << typeid(sub).name() << endl;
	cout << typeid(sub[0]).name() << endl;

	cout << "\n";
	cout << "==============================" << endl;

	int a6[3][3][3] = { 0 };

	cout << "3次元配列の構成要素" << endl;
	cout << "構成要素 : " << sizeof(a6) / sizeof(a6[0][0][0]) << endl;
	cout << sizeof(a6[0]) / sizeof(a6[0][0]) << endl;
	cout << sizeof(a6) / sizeof(a6[0][0]) << endl;

	return 0;
}

// 範囲指定乱数生成	
int GetRandom(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}
