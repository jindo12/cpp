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
    // デフォルトコンストラクタ
    Boolean() : v(False) { }

    // 変換コンストラクタ
    Boolean(int val) : v(val == 0 ? False : True) {   }

    // 変換関数
    operator int() const { return v; }

    operator const char* () const {
        return v == False ? "False" : "True";
    }

};

// 出力ストリームsにxを挿入
inline std::ostream& operator<<(std::ostream& s, Boolean& x) {
    return s << static_cast<const char*>(x);
}

#endif