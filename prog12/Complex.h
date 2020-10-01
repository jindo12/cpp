#pragma once

class Complex {
	double re;
	double im;
public:
	Complex(double r = 0, double i = 0)
		: re(r), im(i) {

	}

	// ’P€‚ÌZp‰‰Zq
	Complex operator+() const { return *this; }

	// •„†”½“]
	Complex operator-() const { return Complex(-re, -im); }

	// 2€+‰‰Zq
	Complex operator+(const Complex& x) {
		return Complex(re + x.re, im + x.im);
	}
};