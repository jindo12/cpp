#include <ctime>
#include <cstdlib>

using namespace std;

static int ans = 0;	// game.cpp���L�̕ϐ�
extern int max_no;	// �P�Ȃ�錾


// ������
void initialize() {
	srand(time(NULL));
}


// ���i���Ă�ׂ����j�̍쐬
void gen_no() {
	ans = rand() % (max_no + 1);
}

// �𓚂̔���
int judge(int cand) {
	if (cand == ans) {
		return 0;	// ����
	}
	else if (cand > ans) {
		return 1;	// �傫��	
	}
	else {
		return 2;	// ������
	}
}
