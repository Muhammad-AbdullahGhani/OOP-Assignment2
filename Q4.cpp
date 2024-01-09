/*
Name:Muhammad Abdullah Ghani
Roll No:22I-2683
*/
#include<iostream>
using namespace std;

class Date {
	int month;
	int day;
	int year;
	public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int d, int m, int y) {
		if (m >= 1 && m <= 12) {
			month = m;
			day = d;
			year = y;
		}
		else {
			month = 1;
			day = d;
			year = y;
		}

	}

	Date(Date& d) {
		day = d.day;
		month = d.month;
		year = d.year;
	}
	void nextday() {
		if (day == 31&&month!=12) {
			month += 1;
			day = 1; this->year = year;
		}
		else if (day == 31 && month == 12) {
			month = 1;
			day = 1;
			year = year + 1;
		}
		else if (day == 28 && month == 2 &&(year % 4 != 0 && year % 400 != 0 && year % 100 != 0)) {
			this->day = 1;
			this->month = 3;
		}
		else if (day == 30 && month == 4 || month == 6 || month == 11 || month == 9) {
			day = 1;
			this->month +=1;
			this->year = year;
		}
		else if (day == 28 && month == 2 && (year % 4 == 0 && year % 400 == 0 && year % 100 == 0)) {
			this->day = 29;
		}
		
		else {
			day -=- 1;
		}

	}
	void displaydate() {
		cout <<"\n" << day << " \\ " << month << " \\ " << year;
	}
	
	
};
int main() {
	Date obn(31, 12, 2022);
	obn.nextday();
	obn.displaydate();
	Date ob(30, 4, 2022);
	ob.nextday();
	ob.displaydate();
	Date obj(31, 1, 2022);
	obj.nextday();
	obj.displaydate();
	Date obs(28, 2, 2004);
	obs.nextday();
	obs.displaydate();
	return 0;
}