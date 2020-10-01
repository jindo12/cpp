#include <iostream>

using namespace std;

void fill_zero(int* p, int n); // []���g��Ȃ��z��v�f�̑���
int seq_search1(int* a, int n, int key); // �lkey����`�T��
int seq_search2(int* a, int n, int key);
int search_idx(int* a, int* idx, int n, int key);

int main(int argc, char const* argv[]) {
	
	int x[5] = { 1,2,3,4,5 };
	int x_zero = sizeof(x) / sizeof(x[0]); // �z�񂘂̗v�f

	int key, idx;
	int x1[8];
	int x1_size = sizeof(x1) / sizeof(x1[0]);

	int x2[7] = { 0 };
	int idx2[7] = { 0 };
	int x2_size = sizeof(x2) / sizeof(x2[0]);

	// �|�C���^�ɂ��z��v�f�̑���
	for (int i = 0; i < x_zero; i++) {
		cout << "x[" << i << "] = " << x[i] << endl;
	}

	fill_zero(&x[0], x_zero);

	cout << "�S�v�f��0�������܂���";

	for (int i = 0; i < x_zero; i++) {
		cout << "x[" << i << "] = " << x[i] << endl;
	}

	cout << "=================================" << endl;

	// ���`�T��1
	cout << "���`�T������1" << endl;
	for (int i = 0; i < x1_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x1[i];
	}

	cout << "�T���l�� : ";
	cin >> key;

	if ((idx = seq_search1(x1, x1_size, key)) != -1)
		cout << "���̒l�����v�f��x[" << idx << "]" << endl;
	else
		cout << "������܂���ł����B" << endl;

	cout << "=================================" << endl;

	// ���`�T��2
	cout << "���`�T������2" << endl;
	for (int i = 0; i < x1_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x1[i];
	}

	cout << "�T���l�� : ";
	cin >> key;

	if ((idx = seq_search2(x1, x1_size, key)) != -1) {
		cout << "���̒l�����v�f��x[" << idx << "]�ł�" << endl;
	}
	else {
		cout << "������܂���ł����B" << endl;
	}

	cout << "=================================" << endl;

	// �v�f��n�̔z��a����key�Ɠ������S�v�f�̓Y������
	// �z��idx�Ɋi�[����֐�search_idx���쐬����
	cout << "�T���l�Ɠ������l�̓Y������z��idx�Ɋi�[���A���̐���Ԃ��B" << endl;
	for (int i = 0; i < x2_size; i++) {
		cout << "x[" << i << "] : ";
		cin >> x2[i];
	}

	cout << "�T���l��:";
	cin >> key;

	if ((idx = search_idx(x2, idx2, x2_size, key) != -1)) {
		cout << key << "�́A" << search_idx(x2, idx2, x2_size, key) << "����܂��B" << endl;
	}
	else {
		cout << "������܂���ł���" << endl;
	}

	cout << "=================================" << endl;

	// ���I�L�������
	int* d1 = new int;		// �s��l�ŏ�����
	// int* x = new int(); // 0�ŏ�����
	int* d2 = new int(5);	// �����F�������q�t��
	cout << "�����F"; cin >> *d1;
	cout << "*d1 = " << *d1 << endl;
	cout << "*d2 = " << *d2 << endl;
	delete d1;
	delete d2;

	cout << "=================================" << endl;

	// �z��I�u�W�F�N�g�̓��I����
	int asize;	// �z��v�f��
	cout << "�v�f�� : "; cin >> asize;
	int* a = new int[asize];

	for (int i = 0; i < asize; i++) {
		a[i] = i;
	}

	for (int i = 0; i < asize; i++) {
		cout << "a[" << i << "] = " << a[i] << endl;
	}

	delete[] a;

	cout << "=================================" << endl;

	// �I�u�W�F�N�g�����̎��s�Ɨ�O����
	//cout << "�v�f��30000��double�^�z����J��Ԃ��������܂��B" << endl;
	//while (true) {
	//	try {
	//		double* a = new double[30000];
	//	}
	//	catch (bad_alloc) {
	//		cout << "�z��̐����Ɏ��s�����̂ŁA�v���O�����𒆒f���܂��B" << endl;
	//		return 1; // �v���O�������f
	//	}
	//}

	//cout << "=================================" << endl;

	// ��̃|�C���^
	//#define NULL 0

	//cout << "=================================" << endl;

	// void�ւ̃|�C���^
	
	int* pi;							// int�ւ̃|�C���^
	void* pv;							// void�ւ̃|�C���^
	cout << "void�ւ̃|�C���^" << endl;
	pv = pi;							// �L���X�g�s�v	
	// pi = pw;							// �G���[�F�L���X�g���K�v
	pi = reinterpret_cast<int*>(pv);	// ok

	cout << "=================================" << endl;

	

	return 0;
}

void fill_zero(int* p, int n) {

	while (n-- > 0) {
		*p = 0; // ���ڗv�f��0����
		p++;	// ���̗v�f�ɒ���
		// *p++ = 0 �i�ȗ��`�j
	}
}

int seq_search1(int* a, int n, int key) {

	for (int i = 0; i < n; i++) {
		if (*a++ == key) {
			return i;	// �T������	
		}
	}
	return -1;		// �T�����s
}

int seq_search2(int* a, int n, int key) {
	int* p = a;

	while (n-- > 0) {
		if (*p == key) {
			return p - a;
		}
		else {
			p++;
		}
	}
	return -1; 
}

int search_idx(int* a, int* idx, int n, int key) {

	int c = 0;
	for (int i = 0; i < n; i++) {
		if (*a++ == key) {
			idx[i] = a[i];
			c++;
		}
	}

	if (c == 0) {
		return -1;
	}

	return c;
}