#include "Driver.h"
#include<iostream>

extern void error(int, char*);


Driver::Driver()
{
}


Driver::~Driver()
{
}

Driver::Driver(int _driverId, std::string _firstName, std::string _lastName)
{
	driverId = _driverId;
	firstName = _firstName;
	lastName = _lastName;

}

void Driver::setDriver(int _driverId, std::string _firstName, std::string _lastName)
{
	driverId = _driverId;
	firstName = _firstName;
	lastName = _lastName;
}

void Driver::setDriver()
{
	try {
		std::cout << "Podaj Id kierowcy:" << std::endl;
		std::cin >> driverId;
		if (std::cin.fail())
			throw 1;
		std::cout << "Podaj imie kierowcy:" << std::endl;
		std::cin >> firstName;
		std::cout << "Podaj nazwisko kierowcy:" << std::endl;
		std::cin >> lastName;
	}
	catch (...)
	{
		error(1, "set driver");
	}
}


void Driver::getDriver()
{
	int x = 15 - firstName.size();
	std::cout << std::setw(4) << driverId << "   " << firstName;
	skip(x);
	std::cout << lastName << std::endl;
}


int Driver::getId()
{
	return driverId;
}

void Driver::setId(int Id)
{
	driverId = Id;
}
