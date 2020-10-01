#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <typeinfo>
#include <cstring>

using namespace std;

void put_str(const char s[]);
void put_upper(const char s[]);

int main(int argc, char const* argv[]) {


	// �������e����
	cout << "���������e����" << endl;
	cout << "�^ ; " << typeid("ABC").name() << " �傫�� : " << sizeof("ABC") << endl;
	cout << "�^ ; " << typeid("").name() << " �傫�� : " << sizeof("") << endl;
	cout << "�^ ; " << typeid("ABC\0DE").name() << " �傫�� : " << sizeof("ABC\0DE") << endl;

	cout << "=================================================" << endl;

	// �z��ɕ�������i�[���ĕ\��

	cout << "���z��ɕ�������i�[���ĕ\��" << endl;

	char s[4];
	s[0] = 'A';
	s[1] = 'B';
	s[2] = 'C';
	s[3] = '\0';

	cout << "�z��a�ɓ����Ă��镶�����" << s << "�ł��B\n";

	cout << "=================================================" << endl;

	// �֐��Ԃ̕�����̎󂯓n��
	char str[34];
	put_str("������ : ");
	cin >> str;
	put_str(str);
	cout << "\n";

	cout << "=================================================" << endl;

	// ��������啶���ɕϊ�
	cout << "����������啶����" << endl;
	put_upper(str);
	cout << "\n";

	cout << "=================================================" << endl;

	// �|�C���^�ɂ�镶����
	char str1[] = "ABC";
	char str2[] = "XYZ";
	char* p = str1;

	cout << p << endl;

	p = str2;

	cout << p << endl;
	
	cout << "=================================================" << endl;

	// strlen�֐�

	char str3[100];
	cout << "���������͂��Ă�������:"; cin >> str3;
	cout << "������\"" << str3 << "\"�̒�����" << strlen(str3) << endl;

	cout << "=================================================" << endl;

	// strcpy, strncpy�֐�
	char tmp[16];
	char s1[16], s2[16], s3[16];
	cout << "���������͂��Ă������� : "; cin >> tmp;
	strcpy(s1, strcpy(s2, tmp)); // tmp��s2�ɃR�s�[�As1�ɂ��R�s�[
	cout << "������s1 : " << s1 << endl;
	cout << "������s2 : " << s2 << endl;
	cout << "������s3 : " << strcpy(s3, tmp) << endl;
	const char* x = "XXXXXXXXX";
	strcpy(s3, x); strncpy(s3, "12345", 3); cout << "s3 = " << s3 << endl;
	strcpy(s3, x); strncpy(s3, "12345", 5); cout << "s3 = " << s3 << endl;
	strcpy(s3, x); strncpy(s3, "12345", 7); cout << "s3 = " << s3 << endl;
	strcpy(s3, x); strncpy(s3, "1234567890", 9); cout << "s3 = " << s3 << endl;

	cout << "=================================================" << endl;

	// strcat, strncat�֐�

	char s4[10];
	const char* x1 = "ABC";

	strcpy(s4, "QWE");
	strcat(s4, "RTY");
	cout << "s4 = " << s4 << endl;

	strcpy(s4, x1); strncat(s4, "123", 1); cout << s4 << endl;
	strcpy(s4, x1); strncat(s4, "123", 3); cout << s4 << endl;
	strcpy(s4, x1); strncat(s4, "123", 5); cout << s4 << endl;
	strcpy(s4, x1); strncat(s4, "123456789", 5); cout << s4 << endl;

	cout << "=================================================" << endl;

	// strcmp, strncmp�֐�

	char st[123];

	cout << "\"ABCDE\"�Ƃ̔�r���s��\n";
	cout << "\"XXXXX\"�ŏI�����܂�\n";

	while (1) {
		cout << "������st : "; cin >> st;
		if (strcmp(st, "XXXXX") == 0) {
			break;
		}
		cout << "strcmp( \"ABCDE\", st) = " << strcmp("ABCDE", st) << endl;
		cout << "strncmp(\"ABCDE\", st, 3) = " << strncmp("ABCDE", st, 3) << endl;
	}

}	

void put_str(const char s[]) {
	for (int i = 0; s[i] != 0; i++) {
		cout << s[i];
	}
}

void put_upper(const char s[]) {
	for (int i = 0; i < s[i]; i++) {
		cout << static_cast<char>(toupper(s[i]));
	}
}