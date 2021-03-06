/// <summary>
/// 日付class
/// </summary>

#ifndef ___Class_Date
#define ___Class_Date

class Date {
	int y;
	int m;
	int d; 

public:
	Date();
	Date(int yy, int mm = 1, int dd = 1);

	int year() { return y; }
	int month() { return m; }
	int day() { return d; }

	Date preceding_day() const; // 前日の日付を返却

	int day_of_week() const; // 曜日を返却

	std::string to_string() const; // 文字列表現
};

std::ostream& operator << 
(std::ostream& a, const Date& x); // 挿入子

#endif
