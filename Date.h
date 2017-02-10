#pragma once
#include<string>
#include<iostream>
#include<iomanip>
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	~Date();
	void setdate();
	bool checkdate();
	void getdate();
	int getyear();
	int getmonth();
	int getday();
	friend class DataBaseTxt;
	friend class Route;
	
	
};

