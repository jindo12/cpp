#include <iostream>
#include <string>

#include <ctime>
#include <cstdlib> // 乱数の生成

using namespace std;

int main(int argc, char const * argv[]) {

	int a;
	a = 1;
	int b = 4;

	srand(time(NULL));

	int lucky = rand() % 10;
	cout << "今日のラッキーナンバーは" << lucky << "です。\n";
	cout << "2で割った商は" << lucky / 2 << "です。\n";
	cout << "2で割った剰余は" << lucky % 2 << "です。\n";

	// 定置オブジェクト（不変）
	const double PI = 3.14;
	double r;

	cout << "半径:";
	cin >> r;
	cout << "半径" << r << "の円の面積は" << (PI * r * r) << "です。\n";

	string name;

	cout << "お名前は:";
	cin >> name; // 空白は読み飛ばす
	cout << "\aこん" "にちは" << name << "さん。\n"; // 空白類をはさむ文字リテラルは連結
	return 0;
}