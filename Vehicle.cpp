#include "Vehicle.h"

extern void error(int, char*);

Vehicle::Vehicle()
{
}


Vehicle::~Vehicle()
{
}


void Vehicle::setVehicle()
{
	try 
	{
		std::cout << "Dodaj id pojazdu: " << std::endl;
		std::cin >> vehicleId;
		if (std::cin.fail())
			throw 1;
		do {
			std::cout << "Podaj typ pojazdu: \n[1]DMC do 3,5Mg \n[2] DMC do 6,5Mg \n[3] DMC powyzej 6,5Mg" << std::endl;
			std::cin >> type;
			if (std::cin.fail())
				throw 1;
		} while (type != 1 & type != 2 && type != 3);
			if (std::cin.fail())
				throw 1;
		
		std::cout << "Dodaj opis pojazdu: " << std::endl;
		std::cin.ignore(25, '\n');
		std::getline(std::cin, description);
	}
	catch(...)
	{
		error(1, "set driver");
	}
}



void Vehicle::getVehicle()
{
	std::cout << std::setw(4) << vehicleId << "   " << std::setw(4) << type << "   " << description << std::endl;
}

int Vehicle::getId()
{
	return vehicleId;
}

int Vehicle::getType()
{
	return type;
}


void Vehicle::setId(int Id)
{
	vehicleId = Id;
}

