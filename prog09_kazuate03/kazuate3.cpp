#include <iostream>
#include "kazuate3.h"

using namespace std;

int max_no = 999;

int main(int argc, char const* argv[]) {

	// 数当ゲーム

	//10回まで
	//入力ミスを行った場合は、回数としてカウントしない。
	//聖化した場合は難解で正解したかを表示し、最後まで正解しなかった倍は正解を表示する。
	
	initialize();
	cout << "数当ゲーム開始！(10回まで)" << endl;

	do {

		int s = create_q();
		int flag;

		do {
			flag = judge(input());
			
			if (c == 10) {
				break;
			}
			if (flag == 1) {
				cout << "小さい" << endl;
				gameCount();
			}
			
			else if (flag == 2) {
				cout << "大きい" << endl;
				gameCount();

			}
		} while (flag != 0);

		if (flag == 0) {
			cout << "正解です。" << endl;
		}else if (c != 10) {
			cout << "正解です。" << endl;
			initialize();
		}
		else {
			cout << "GAME OVRE!!!!" << endl;
			cout << "正解は" << s << endl;
			initialize();
		}
		

	} while (comfirm_retry());
		
	
}