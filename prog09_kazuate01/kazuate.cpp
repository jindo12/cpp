#include <iostream>

using namespace std;

void initialize();		// [初期化] 乱数の種を現在時刻に基づいて設定
void gen_no();			// [問題の作成] 0~max_noの値を乱数で生成
int judge(int cand);	// [解答の判定] candが正解かどうかを判定
int input();			// [解答の入力] 0~max_noの値を入力さｓる
bool confirm_retry();	// [続行の確認]

int max_no = 9;	// 当てるべき数の最大値

int main(int argc, char const* argv[]) {

	initialize();
	cout << "数当ゲーム開始!" << endl;

	do {
		
		gen_no();
		int flag;

		do {
			flag = judge(input());
			if (flag == 1) {
				cout << "もっと小さい" << endl;
			}
			else if (flag == 2) {
				cout << "もっと大きい" << endl;
			}
		} while (flag != 0);

		cout << "正解！！！" << endl;

	} while (confirm_retry());
	
}

