#include "Route.h"



Route::Route()
{
	driverId = 0;
	vehicleId = 0;
	clientId = 0;
	kilometers = 0;
}


Route::~Route()
{
}

void Route::setdate()
{
	date.setdate();
}

void Route::setRoute()
{
	std::cout << "Ile kilometrow przejechales ? " << std::endl;
	std::cin >> kilometers;
	std::cin.ignore(25, '\n');
	std::cout << "Miejsce wyjazdu:" << std::endl;
	std::getline(std::cin, routeDestination);
	std::cout << "Cel wyjazdu:" << std::endl;
	std::getline(std::cin, routeObject);
}

void Route::setKilometers()
{
	std::cout << "Ile kilometrow przejechales ? " << std::endl;
	std::cin >> kilometers;
}

void Route::setObject()
{
	std::cout << "Cel wyjazdu:" << std::endl;
	std::getline(std::cin, routeObject);
}

void Route::setDestination()
{
	std::cin.ignore(25, '\n');
	std::cout << "Miejsce wyjazdu:" << std::endl;
	std::getline(std::cin, routeDestination);
}


void Route::setClientId(int id)
{
	clientId = id;
}



void Route::setDriverId(int id)
{
	driverId = id;
}


void Route::setVehicleId(int id)
{
	vehicleId = id;
}

void Route::getRoute()
{
		date.getdate();
		int x = 15 - routeDestination.size();
		int y = 15 - routeObject.size();

		std::cout << "  " << std::setw(4) << kilometers << "  " << routeDestination;
		skip(x); std::cout << routeObject; skip(y + 6); std::cout << std::setw(4) << vehicleId;
		skip(9); std::cout << std::setw(4) << driverId; skip(8);
		std::cout << std::setw(4) << clientId <<  std::endl;
}


void Route::getRouteToMenu()
{
	std::cout << "Data"; skip(9); std::cout << "KM   " << "Miejsce";
	skip(8); std::cout << "Cel"; skip(12); std::cout << "Id Pojazdu  " << "Id kierowcy  " << "Id kilenta" << std::endl;
	getRoute();
	std::cout << "\n";
}


bool Route::operator<(const Route& route)
{
	if (this->date.year < route.date.year)
	{
		return 1;
	}
	else if (this->date.year == route.date.year)
	{
		if (this->date.month < route.date.month)
			return 1;
		else if (this->date.month == route.date.month)
		{
			if (this->date.day < route.date.day)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}