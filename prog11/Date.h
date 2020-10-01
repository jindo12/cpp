/// <summary>
/// “ú•tclass
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

	Date preceding_day() const; // ‘O“ú‚Ì“ú•t‚ð•Ô‹p

	int day_of_week() const; // —j“ú‚ð•Ô‹p

	std::string to_string() const; // •¶Žš—ñ•\Œ»
};

std::ostream& operator << 
(std::ostream& a, const Date& x); // ‘}“üŽq

#endif
