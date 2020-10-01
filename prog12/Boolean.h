#pragma once

#ifndef ___Class_Boolean
#define ___Class_Boolean

#include <iostream>

class Boolean {
public:
    enum boolean {False, True};

private:
    boolean v;

public:
    // �f�t�H���g�R���X�g���N�^
    Boolean() : v(False) { }

    // �ϊ��R���X�g���N�^
    Boolean(int val) : v(val == 0 ? False : True) {   }

    // �ϊ��֐�
    operator int() const { return v; }

    operator const char* () const {
        return v == False ? "False" : "True";
    }

};

// �o�̓X�g���[��s��x��}��
inline std::ostream& operator<<(std::ostream& s, Boolean& x) {
    return s << static_cast<const char*>(x);
}

#endif