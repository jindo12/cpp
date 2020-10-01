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
	int a_size = sizeof(a) / sizeof(a[0]); // �z��a�̗v�f��

	const int m = 5; // ��u�I�u�W�F�N�g
	const int m1 = 6;
	const int m2 = 15;
	int score[m];
	int array1[m], c1 = 0;
	float array2[m];
	int array3[m1];
	int array4[m2];
	int b = 0;
	int sum = 0;

	// 1~5��
	for (int i = 0; i < a_size; i++) {
		cout << a[i] << endl;
	}

	cout << "=============================" << endl;

	cout << m << "�l�̓_���̍��v�_�ƕ��ϓ_�����Ƃ߂�" << endl;

	for (int i = 0; i < m; i++) {
		cout << i + 1 << "�Ԃ̓_�� : ";
		cin >> score[i];
		sum += score[i];
	}

	cout << "sum : " << sum << endl;
	cout << "ave : " << static_cast<double>(sum) / m << endl;

	cout << "==============================" << endl;

	cout << "�v�f��5�̔z��̗v�f�ɑ΂��āA�擪���珇��54321�������ĕ\����" << endl;

	for (int i = 5; i > 0; i--) {
		array1[c1] = i;
		cout << array1[c1] << endl;
		c1++;
		
	}

	cout << "==============================" << endl;

	cout << "���������_�^double�ŗv�f����5�̑S�v�f�ɑ΂���0.0�������ĕ\��" << endl;

	// �����_�ȉ��̒������w��
	cout << fixed << setprecision(1);
	for (int i = 0; i < 5; i++) {
		array2[i] = 0.0F;
		cout << array2[i] << endl;
	}

	cout << "==============================" << endl;

	cout << "�v�f�^��int, �v�f��6�̔z��̑S�v�f���P�`�P�O�̗����Ŗ��ߐs����" << endl;

	for (int i = 0; i < 6; i++) {
		int random = rand() % 10 + 1;
		array3[i] = random;
		cout << array3[i] << endl;
	}

	cout << "==============================" << endl;

	cout << "�A������v�f�������l�ƂȂ�Ȃ��悤�ɁA������������" << endl;
	for (int i = 0; i < 6; i++) {
		int random = rand() % 10 + 1;
		array3[i] = random;
		cout << array3[i] << endl;
	}

	for (int i = m1; i > 1; i--) {
		int random = rand() % 10 + 1;
		if (array3[i - 2] == array3[i - 1]) {
			cout << "\n";
			cout << i - 2 << "�Ԗ�:" << array3[i - 2] << " == " << i - 1 << "�Ԗ�:" << array3[i - 1] << endl;
			array3[i - 1] = random;
			cout << "\n";
		}
		
	}

	cout << "\n";

	for (int i = 0; i < 6; i++) {
		cout << array3[i] << endl;
	}

	cout << "==============================" << endl;

	

	// �z���0~10�̗�������

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
			// �v�f�̒l���ő�l�ȏ�̏ꍇ�A*���o��
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


	cout << "�y�z�񔽓]�z" << endl;

	int head = 0;
	int tail = 0;
	int center = 0;

	// ���]�O
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

	// ���]��
	for (int i = 0; i < m2; i++) {
		cout << "a[" << i << "] = " << array4[i] << endl;
	}

	cout << "\n";
	cout << "==============================" << endl;

	// �z��̗v�f���̕��т��V���b�t��
	cout << "�V���b�t��" << endl;
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

	cout << "�z��̃R�s�[" << endl;
	
	const int n = 5;
	int d[n];							// �R�s�[��
	int e[n] = { 0 };					// �R�s�[��

	// �z��ɒl��ǂݍ���
	for (int i = 0; i < n; i++) {
		cout << "d[" << i << "] : ";
		cin >> d[i];
	}

	// �z��d�̑S�v�f��z��ɃR�s�[
	for (int i = 0; i < n; i++) {
		e[i] = d[i];
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << "e[" << i << "] = " << e[i] << "\n";
	}

	cout << "\n";
	cout << "==============================" << endl;

	cout << "�������z��" << endl;

	int array5[3][2];

	cout << "�e�\���v�f�̒l��������B" << endl;
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
		cout << "(4�s�E3��), �l��������B" << endl;
		for (int j = 0; j < 3; j++) {
			cout << "f[" << i << "][" << j << "] : ";
			cin >> f[i][j];
		}
	}
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		cout << "(3�s�E4��), �l��������B" << endl;
		for (int j = 0; j < 4; j++) {
			cout << "g[" << i << "][" << j << "] : ";
			cin >> g[i][j];
		}
	}
	cout << "\n";

	// �s��̐�
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

	// 6�l��2�Ȗځi����E���w�j�̓_����ǂݍ���
	int sub[6][2] = { 0 };
	int s[6] = { 0 }; // �w�����Ƃ̍��v
	int sum1 = 0; // ����
	int sum2 = 0; // ���w


	for (int i = 0; i < 6; i++) {
		cout << "����E���w : ";
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
		cout << "s[" << i << "] ����̍��v�_ ; " << s[i] << "�_, ���ϓ_:" << s[i]/2  << "�_" << endl;
	}
	
	cout << "-----------------------------------------------" << endl;
	cout << "<����> (���v�_�j: " << setw(3) << sum1 <<  ", (���ϓ_�j: " << setw(3) << sum1/6 << endl;
	cout << "<���w>�i���v�_�j: " << setw(3) << sum2 <<  ", (���ϓ_�j: " << setw(3) << sum2/6 << endl;

	cout << "\n";
	cout << "==============================" << endl;

	cout << "�z��sub��" << sizeof(sub) / sizeof(sub[0]) << "�s"
		<< sizeof(sub[0]) / sizeof(sub[0][0]) << "��ł��B" << endl;
	cout << "�\���v�f��" << sizeof(sub) / sizeof(sub[0][0]) << "�ł��B" << endl;
	cout << typeid(sub).name() << endl;
	cout << typeid(sub[0]).name() << endl;

	cout << "\n";
	cout << "==============================" << endl;

	int a6[3][3][3] = { 0 };

	cout << "3�����z��̍\���v�f" << endl;
	cout << "�\���v�f : " << sizeof(a6) / sizeof(a6[0][0][0]) << endl;
	cout << sizeof(a6[0]) / sizeof(a6[0][0]) << endl;
	cout << sizeof(a6) / sizeof(a6[0][0]) << endl;

	return 0;
}

// �͈͎w�藐������	
int GetRandom(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}
