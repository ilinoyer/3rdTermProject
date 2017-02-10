#include<string>
#include<iomanip>
#pragma once
class Driver
{
private:
	int driverId;
	std:: string firstName;
	std:: string lastName;

public:
	Driver();
	~Driver();
	Driver(int, std::string, std::string);
	void setDriver(int, std::string, std::string);
	void setDriver();
	void setId(int);
	void getDriver();
	int getId();
	friend void skip(int);

	friend class DataBaseTxt;
	friend class Data;
};

