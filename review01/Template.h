#pragma once
#include <cstring>

class Template
{
public:
	template <typename Type> Type maxof(Type a, Type b);
	// ��r�Ώۂ�������Ȃ�΁A�����I�ȓ��ꉻ
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

//�@�w�b�_�t�@�C���ł̃e���v���[�g�֐��̗��p
//�@�́A��`�����Ǝ��������ŕ������邱�Ƃ��ł��Ȃ��̂�
//	�܂Ƃ߂�h�t�@�C�����ɂ����B

