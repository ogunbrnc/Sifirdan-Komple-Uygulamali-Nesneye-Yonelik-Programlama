#include <iostream>
using namespace std;

class Date {
public:
	Date(int d=1, int m=1, int y=1900);
	Date(const Date& oth);
	~Date();
	void setDate(int d=1, int m=1, int y=1800);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay() { return day; };
	int getMonth() { return month; };
	int getYear() { return year;};
	void increaseDay();
	void compareDate(const Date &othDate);
	void displayDate();
private:
	int year, month, day;
	const int monthDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	const string monthString[12] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
};


Date::Date(int d, int m, int y) {
	setDate(d, m, y);
}
Date::~Date() {
	cout << "Date destroyed." << endl;
}
Date::Date(const Date& oth) {
	day = oth.day;
	month = oth.month;
	year = oth.year;
	cout << "Date copied to target." << endl;
}
void Date::setDate(int d, int m, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
	cout << "Date created." << endl;
}
void Date::setDay(int d) {
	if (d >= 1 && d<=monthDays[month - 1]) {
		day = d;
	}
	else {
		day = 1;
	}
}
void Date::setMonth(int m) {
	if (m <= 12 && m >= 1) {
		month = m;
	}
	else {
		month = 1;
	}
}
void Date::setYear(int y) {
	if(y>=1800){
		year = y;
	}
	else{
		year = 1800;
	}
}
void Date::increaseDay() {
	if (day < monthDays[month - 1]) {
		day++;
	}
	else {
		day = 1;
		if (month < 12) {
			month++;
		}
		else {
			month = 1;
			year++;
		}
	}
}
void Date::displayDate() {
	cout << day << " " << monthString[month - 1] << " " << year << endl;
}
void Date::compareDate(const Date &othDate) {
	long dayFirst;
	long daySecond;
	dayFirst = year * 365 + month * 12 + day;
	daySecond = othDate.year * 365 + othDate.month * 12 + othDate.day;

	if (dayFirst > daySecond) {
		cout << "First date is greater!" << endl;
	}
	else if (dayFirst < daySecond) {
		cout << "Second date is greater!" << endl;
	}
	else {
		cout << "Equal!"<<endl;
	}
}