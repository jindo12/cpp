#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include "Date.h"

Date::Date()
{
	time_t current = time(NULL);			// 現在の暦時刻を取得
	//struct tm* local = localtime(&current); // 要素別の時刻に変換
	struct tm local_time;	// 

	localtime_s(&local_time, &current);
	
	y = local_time.tm_year + 1900; // 年 : 西暦年　- 1900
	m = local_time.tm_mon + 1;	   // 月 : 0 ~ 11		
	d = local_time.tm_mday;		   // 日
}

Date::Date(int yy, int mm, int dd) {
	y = yy;
	m = mm;
	d = dd;
}


// 前日の日付を返却 Date型
Date Date::preceding_day() const {
	// 各月ごとの日付の最大値
	int dmax[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date tmp = *this; // 同一の日付

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

// thisを利用したpreceding_day関数
//Date Date::preceding_day() const {
//	int dmax[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int y = this->y;
//	int m = this->m;
//	int d = this->d;
//
//	if (d > 1) {
//		d--;；
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

// 曜日を返却
int Date::day_of_week() const {
	int yy = y;
	int mm = m;
	if (mm == 1 || mm == 2) {
		yy--;
		mm += 12;
	}
	// ツェラーの公式
	return (yy + yy / 4 - yy / 100 + yy / 400 + (13 * mm + 8) / 5 + d) % 7;
}

// 文字列表現を返却
std::string Date::to_string() const {
	std::ostringstream s;
	s << y << "/" << m << "/" << d << "/" << std::endl;
	return s.str();
}

// 出力ストリームsにxを挿入
std::ostream& operator << (std::ostream& s, const Date& x) {
	return s << x.to_string();
}