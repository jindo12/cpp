#include <iostream>

using namespace std;

void initialize();		// [������] �����̎�����ݎ����Ɋ�Â��Đݒ�
void gen_no();			// [���̍쐬] 0~max_no�̒l�𗐐��Ő���
int judge(int cand);	// [�𓚂̔���] cand���������ǂ����𔻒�
int input();			// [�𓚂̓���] 0~max_no�̒l����͂�����
bool confirm_retry();	// [���s�̊m�F]

int max_no = 9;	// ���Ă�ׂ����̍ő�l

int main(int argc, char const* argv[]) {

	initialize();
	cout << "�����Q�[���J�n!" << endl;

	do {
		
		gen_no();
		int flag;

		do {
			flag = judge(input());
			if (flag == 1) {
				cout << "�����Ə�����" << endl;
			}
			else if (flag == 2) {
				cout << "�����Ƒ傫��" << endl;
			}
		} while (flag != 0);

		cout << "�����I�I�I" << endl;

	} while (confirm_retry());
	
}

