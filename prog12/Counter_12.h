#pragma once

#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

class Counter {
	unsigned cnt;

public:

	// default constructor
	Counter() : cnt(0) {	}

	// unsigned型への変換関数
	operator unsigned() const { return cnt; }

	// 論理否定演算子!
	bool operator!() const { return cnt == 0; }

	// 前置増分演算子++
	Counter& operator++() {
		if (cnt < UINT_MAX) cnt++;
		return *this;
	}

	// 後置増分演算子++
	Counter operator++(int) {
		Counter x = *this;
		if (cnt < UINT_MAX) cnt++;
		return x;
	}

	// 前置減分演算子++
	Counter& operator--() {
		if (cnt < UINT_MAX) cnt--;
		return *this;
	}

	// 後置減分演算子++
	Counter operator--(int) {
		Counter x = *this;
		if (cnt < UINT_MAX) cnt--;
		return x;
	}

	void increment() { if (cnt < UINT_MAX) cnt++; }

	void decrement() { if (cnt > 0) cnt--; }

	unsigned value() { return cnt; }

};

#endif