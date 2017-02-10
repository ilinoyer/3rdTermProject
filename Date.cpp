#include "Date.h"
#include<iostream>
#include<string>
using namespace std;

extern void error(int, char*);

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}


Date::~Date()
{
}

void Date::setdate()
{
	int p;
	try {
		do {
			system("cls");
			cout << "Pamietaj dzien, miesiac, rok, kilometry i kazde id wprowadz w postaci liczbowej!" << endl;
			cout << "Wprowadz poprawna date: " << endl;
			cout << "Dzien: ";
			cin >> day;
			if (cin.fail())
				throw 1;
			cout << "Miesiac: ";
			cin >> month;
			cout << "Rok: ";
			cin >> year;
		} while (checkdate() != 1);
	}
	catch (...)
	{
		error(1, "data");
	}
}

bool Date::checkdate()
{
	try {


		if (year < 0)
		{
			//cout << "Podaj rok z naszej ery! :) " << endl;
			throw 1;
		}
		else if (month < 1 || month > 12)
		{
			//cout << "Zle wprowadzony miesiac. Podaj wartosc 1-12!" << endl;
			throw 2;
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day > 30)
			{
				//cout << "Zle wprowadzony dzien miesiaca. Podaj wartosc 1-30!" << endl;
				throw 3;
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day > 31)
			{
				//cout << "Zle wprowadzony dzien miesiaca. Podaj wartosc 1-31!" << endl;
				throw 4;
			}
		}

		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (month == 2 && day > 29)
			{
				//cout << "Luty w roku przestêpnym ma 29 dni !" << endl;
				throw 5;
			}
		}
		else
		{
			if (month == 2 && day > 28)
			{
				//cout << "Luty w roku przestêpnym ma 28 dni !" << endl;
				throw 6;
			}
		}
	}
	catch (...)
	{
		//cout << "Data wprowadzona nie poprawnie " << endl;
		//error(1, "Data");
		return 0;
	}

	return 1;
}



void Date::getdate()
{
	cout <<	setw(2) << day << "." << setw(2) << month << "." << year;
}


int Date::getday()
{
	return day;
}

int Date::getmonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}