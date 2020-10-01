#include <ctime>
#include <cstdlib>

using namespace std;

static int ans = 0;	// game.cpp特有の変数
extern int max_no;	// 単なる宣言


// 初期化
void initialize() {
	srand(time(NULL));
}


// 問題（当てるべき数）の作成
void gen_no() {
	ans = rand() % (max_no + 1);
}

// 解答の判定
int judge(int cand) {
	if (cand == ans) {
		return 0;	// 正解
	}
	else if (cand > ans) {
		return 1;	// 大きい	
	}
	else {
		return 2;	// 小さい
	}
}
