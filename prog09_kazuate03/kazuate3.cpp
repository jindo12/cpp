#include <iostream>
#include "kazuate3.h"

using namespace std;

int max_no = 999;

int main(int argc, char const* argv[]) {

	// �����Q�[��

	//10��܂�
	//���̓~�X���s�����ꍇ�́A�񐔂Ƃ��ăJ�E���g���Ȃ��B
	//���������ꍇ�͓���Ő�����������\�����A�Ō�܂Ő������Ȃ������{�͐�����\������B
	
	initialize();
	cout << "�����Q�[���J�n�I(10��܂�)" << endl;

	do {

		int s = create_q();
		int flag;

		do {
			flag = judge(input());
			
			if (c == 10) {
				break;
			}
			if (flag == 1) {
				cout << "������" << endl;
				gameCount();
			}
			
			else if (flag == 2) {
				cout << "�傫��" << endl;
				gameCount();

			}
		} while (flag != 0);

		if (flag == 0) {
			cout << "�����ł��B" << endl;
		}else if (c != 10) {
			cout << "�����ł��B" << endl;
			initialize();
		}
		else {
			cout << "GAME OVRE!!!!" << endl;
			cout << "������" << s << endl;
			initialize();
		}
		

	} while (comfirm_retry());
		
	
}