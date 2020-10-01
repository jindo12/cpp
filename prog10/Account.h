#pragma once
#include <string>

//ヘッダ部でのクラスの定義

class Account {
	std::string full_name;
	std::string number;
	long crnt_balance;

public:
	Account(std::string name, std::string num, long amnt);

	std::string name() { return full_name; }
	std::string no() { return number; }
	long balance() { return crnt_balance; }

	void deposit(long amnt);
	void widthdraw(long amnt);

	// arrow演算子
	void print_Account(std::string title, Account* p);
};

// 全てのメンバ関数は、内部結合をもつインライン関数
class Car {
	std::string name;
	int width, length, height;	// 車幅・車長・車高
	double xp, yp;				// 現在位置座標
	double fuel_lebel;

public:
	Car(std::string n, int w, int l, int h, double f) {
		name = n; width = w; length = l; height = h; fuel_lebel = f;
		xp = yp = 0.0;
	}

	double x() { return xp; }
	double y() { return yp; }

	double fuel() { return fuel_lebel; }	// 残量

	void print_spec() {
		std::cout << "名前 : " << name << std::endl;
		std::cout << "車幅 : " << width << std::endl;
		std::cout << "車長 : " << length << std::endl;
		std::cout << "車高 : " << height << std::endl;
	}

	bool move(double dx, double dy) {
		double distance = sqrt(dx * dx + dy * dy);	// 移動距離

		if (distance > fuel_lebel) {
			return false;	// 燃料不足
		}
		else {
			fuel_lebel -= distance;
			xp += dx;
			yp += dy;
			return true;
		}
	}

};

