#pragma once
#include <string>

//�w�b�_���ł̃N���X�̒�`

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

	// arrow���Z�q
	void print_Account(std::string title, Account* p);
};

// �S�Ẵ����o�֐��́A�������������C�����C���֐�
class Car {
	std::string name;
	int width, length, height;	// �ԕ��E�Ԓ��E�ԍ�
	double xp, yp;				// ���݈ʒu���W
	double fuel_lebel;

public:
	Car(std::string n, int w, int l, int h, double f) {
		name = n; width = w; length = l; height = h; fuel_lebel = f;
		xp = yp = 0.0;
	}

	double x() { return xp; }
	double y() { return yp; }

	double fuel() { return fuel_lebel; }	// �c��

	void print_spec() {
		std::cout << "���O : " << name << std::endl;
		std::cout << "�ԕ� : " << width << std::endl;
		std::cout << "�Ԓ� : " << length << std::endl;
		std::cout << "�ԍ� : " << height << std::endl;
	}

	bool move(double dx, double dy) {
		double distance = sqrt(dx * dx + dy * dy);	// �ړ�����

		if (distance > fuel_lebel) {
			return false;	// �R���s��
		}
		else {
			fuel_lebel -= distance;
			xp += dx;
			yp += dy;
			return true;
		}
	}

};

