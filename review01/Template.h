#pragma once
#include <cstring>

class Template
{
public:
	template <typename Type> Type maxof(Type a, Type b);
	// 比較対象が文字列ならば、明示的な特殊化
	//template <> const char* maxof<const char*>(const char* a, const char* b);
};

template <typename Type>
Type Template::maxof(Type a, Type b) 
{
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

//template <>
//const char* Template::maxof<const char*>(const char* a, const char* b) {
//	return strcmp(a, b) > 0 ? a : b;
//}

//　ヘッダファイルでのテンプレート関数の利用
//　は、定義部分と実装部分で分割することができないので
//	まとめてhファイル内にかく。

