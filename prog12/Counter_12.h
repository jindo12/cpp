#pragma once

#ifndef ___Class_Counter
#define ___Class_Counter

#include <climits>

class Counter {
	unsigned cnt;

public:

	// default constructor
	Counter() : cnt(0) {	}

	// unsigned�^�ւ̕ϊ��֐�
	operator unsigned() const { return cnt; }

	// �_���ے艉�Z�q!
	bool operator!() const { return cnt == 0; }

	// �O�u�������Z�q++
	Counter& operator++() {
		if (cnt < UINT_MAX) cnt++;
		return *this;
	}

	// ��u�������Z�q++
	Counter operator++(int) {
		Counter x = *this;
		if (cnt < UINT_MAX) cnt++;
		return x;
	}

	// �O�u�������Z�q++
	Counter& operator--() {
		if (cnt < UINT_MAX) cnt--;
		return *this;
	}

	// ��u�������Z�q++
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