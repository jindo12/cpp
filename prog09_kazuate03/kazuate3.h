#pragma once

void initialize();
int create_q();	// 問題を生成
int judge(int cand);
int input();
bool comfirm_retry();
int gameCount();

extern int max_no;	// 当てるべき数の最大値
extern int c;