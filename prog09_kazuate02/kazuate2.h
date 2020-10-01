#pragma once

void initialize();		// [初期化]
void gen_no();			// [問題の作成]
int judge(int cand);	// [解答の判定]
int input();			// [解答の入力]
bool confirm_retry();	// [続行の確認]

extern int max_no;		// 当てるべき数の最大値