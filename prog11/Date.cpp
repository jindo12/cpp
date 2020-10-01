#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include "Date.h"

Date::Date()
{
	time_t current = time(NULL);			// ���݂̗�����擾
	//struct tm* local = localtime(&current); // �v�f�ʂ̎����ɕϊ�
	struct tm local_time;	// 

	localtime_s(&local_time, &current);
	
	y = local_time.tm_year + 1900; // �N : ����N�@- 1900
	m = local_time.tm_mon + 1;	   // �� : 0 ~ 11		
	d = local_time.tm_mday;		   // ��
}

Date::Date(int yy, int mm, int dd) {
	y = yy;
	m = mm;
	d = dd;
}


// �O���̓��t��ԋp Date�^
Date Date::preceding_day() const {
	// �e�����Ƃ̓��t�̍ő�l
	int dmax[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date tmp = *this; // ����̓��t

	if (tmp.d > 1) {
		tmp.d--;
	}
	else {					// 2010/10/1
		if (--tmp.m < 1) {	// 2010/1/24
			tmp.y--;		// 2009
			tmp.m = 12;		// 12
		}
		tmp.d = dmax[tmp.m - 1];
	}
	return tmp;
}

// this�𗘗p����preceding_day�֐�
//Date Date::preceding_day() const {
//	int dmax[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int y = this->y;
//	int m = this->m;
//	int d = this->d;
//
//	if (d > 1) {
//		d--;�G
//	}
//	else {
//		if (--m < 1) {
//			y--;
//			m = 12;
//		}
//		d = dmax[m - 1];
//	}
//	return Date(y, m, d);
//}

// �j����ԋp
int Date::day_of_week() const {
	int yy = y;
	int mm = m;
	if (mm == 1 || mm == 2) {
		yy--;
		mm += 12;
	}
	// �c�F���[�̌���
	return (yy + yy / 4 - yy / 100 + yy / 400 + (13 * mm + 8) / 5 + d) % 7;
}

// ������\����ԋp
std::string Date::to_string() const {
	std::ostringstream s;
	s << y << "/" << m << "/" << d << "/" << std::endl;
	return s.str();
}

// �o�̓X�g���[��s��x��}��
std::ostream& operator << (std::ostream& s, const Date& x) {
	return s << x.to_string();
}