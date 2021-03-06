#pragma once

#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

class Counter {
	unsigned cnt;

public:

	// default constructor
	Counter() : cnt(0) {	}

	// unsigned^ΦΜΟ·Φ
	operator unsigned() const { return cnt; }

	// _ΫθZq!
	bool operator!() const { return cnt == 0; }

	// OuͺZq++
	Counter& operator++() {
		if (cnt < UINT_MAX) cnt++;
		return *this;
	}

	// γuͺZq++
	Counter operator++(int) {
		Counter x = *this;
		if (cnt < UINT_MAX) cnt++;
		return x;
	}

	// OuΈͺZq++
	Counter& operator--() {
		if (cnt < UINT_MAX) cnt--;
		return *this;
	}

	// γuΈͺZq++
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