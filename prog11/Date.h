/// <summary>
/// ���tclass
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

	Date preceding_day() const; // �O���̓��t��ԋp

	int day_of_week() const; // �j����ԋp

	std::string to_string() const; // ������\��
};

std::ostream& operator << 
(std::ostream& a, const Date& x); // �}���q

#endif
