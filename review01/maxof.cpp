#include "maxof.h"

template <typename Type> 
	Type max_of(Type a, Type b) {
		if (a > b) {
			return a;
		}
		else {
			return  b;
		}
}

	template int max_of<int>(int, int);