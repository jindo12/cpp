#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <typeinfo>
#include <cstring>

using namespace std;

void put_str(const char s[]);
void put_upper(const char s[]);

int main(int argc, char const* argv[]) {


	// 文字リテラル
	cout << "◆文字リテラル" << endl;
	cout << "型 ; " << typeid("ABC").name() << " 大きさ : " << sizeof("ABC") << endl;
	cout << "型 ; " << typeid("").name() << " 大きさ : " << sizeof("") << endl;
	cout << "型 ; " << typeid("ABC\0DE").name() << " 大きさ : " << sizeof("ABC\0DE") << endl;

	cout << "=================================================" << endl;

	// 配列に文字列を格納して表示

	cout << "◆配列に文字列を格納して表示" << endl;

	char s[4];
	s[0] = 'A';
	s[1] = 'B';
	s[2] = 'C';
	s[3] = '\0';

	cout << "配列aに入っている文字列は" << s << "です。\n";

	cout << "=================================================" << endl;

	// 関数間の文字列の受け渡し
	char str[34];
	put_str("文字列 : ");
	cin >> str;
	put_str(str);
	cout << "\n";

	cout << "=================================================" << endl;

	// 小文字を大文字に変換
	cout << "小文字から大文字へ" << endl;
	put_upper(str);
	cout << "\n";

	cout << "=================================================" << endl;

	// ポインタによる文字列
	char str1[] = "ABC";
	char str2[] = "XYZ";
	char* p = str1;

	cout << p << endl;

	p = str2;

	cout << p << endl;
	
	cout << "=================================================" << endl;

	// strlen関数

	char str3[100];
	cout << "文字列を入力してください:"; cin >> str3;
	cout << "文字列\"" << str3 << "\"の長さは" << strlen(str3) << endl;

	cout << "=================================================" << endl;

	// strcpy, strncpy関数
	char tmp[16];
	char s1[16], s2[16], s3[16];
	cout << "文字列を入力してください : "; cin >> tmp;
	strcpy(s1, strcpy(s2, tmp)); // tmpをs2にコピー、s1にもコピー
	cout << "文字列s1 : " << s1 << endl;
	cout << "文字列s2 : " << s2 << endl;
	cout << "文字列s3 : " << strcpy(s3, tmp) << endl;
	const char* x = "XXXXXXXXX";
	strcpy(s3, x); strncpy(s3, "12345", 3); cout << "s3 = " << s3 << endl;
	strcpy(s3, x); strncpy(s3, "12345", 5); cout << "s3 = " << s3 << endl;
	strcpy(s3, x); strncpy(s3, "12345", 7); cout << "s3 = " << s3 << endl;
	strcpy(s3, x); strncpy(s3, "1234567890", 9); cout << "s3 = " << s3 << endl;

	cout << "=================================================" << endl;

	// strcat, strncat関数

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

	// strcmp, strncmp関数

	char st[123];

	cout << "\"ABCDE\"との比較を行う\n";
	cout << "\"XXXXX\"で終了します\n";

	while (1) {
		cout << "文字列st : "; cin >> st;
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