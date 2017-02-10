#include "Data.h"
#include<vector>



Data::Data()
{
}


Data::~Data()
{
}


void Data::showDrivers()
{
	int j = Drivers.size();
	std::cout << "Lp" << "    " << "Id";
	skip(3); std::cout << "Imie";
	skip(11); std::cout << "Nazwisko" << std::endl;
	for (int k = 0; k < j; k++)
	{
		std::cout << std::setw(2) << k + 1 << "  ";
		Drivers[k].getDriver();
	}
}


void Data::showClients()
{
	int j = Clients.size();
	std::cout << "Lp" << "    " << "Id" << "   " << "Nazwa Firmy" << std::endl;
	for (int k = 0; k < j; k++)
	{
		std::cout << std::setw(2) << k + 1 << "  ";
		Clients[k].getClient();
	}
}


void Data::showVehicles()
{
	int j = Vehicles.size();
	std::cout << "Lp" << "    " << "Id" << "   " << " Typ" << "   " << "Opis" << std::endl;
	for (int k = 0; k < j; k++)
	{
		std::cout << std::setw(2) << k + 1 << "  ";
		Vehicles[k].getVehicle();
	}

}


void Data::showRoutes()
{
	int j = Routes.size();
	std::cout << "Lp  " << "Data"; skip(9); std::cout << "KM   " << "Miejsce";
	skip(8); std::cout << "Cel"; skip(12); std::cout << "Id Pojazdu  " << "Id kierowcy  " << "Id kilenta" << std::endl;
	for (int k = 0; k < j; k++)
	{
		std::cout << std::setw(2) << k + 1 << "  ";
		Routes[k].getRoute();
	}

}


bool Data::checkDriverId(int id)
{
	for (int i = 0; i < Data::Drivers.size(); i++)
	{
		if (id == Data::Drivers[i].driverId)
			return 0;
	}

	return 1;
}

bool Data::checkClientId(int id)
{
	for (int i = 0; i < Data::Clients.size(); i++)
	{
		if (id == Data::Clients[i].clientId)
			return 0;
	}

	return 1;
}

bool Data::checkVehicleId(int id)
{
	for (int i = 0; i < Data::Vehicles.size(); i++)
	{
		if (id == Data::Vehicles[i].vehicleId)
			return 0;
	}

	return 1;
}


int Data::getMaxId(int choice)
{
	if (choice == 1)
	{
		int maxid = Drivers[0].driverId;
		for (int i = 0; i < Drivers.size(); i++)
		{
			if (Drivers[i].driverId > maxid)
				maxid = Drivers[i].driverId;
		}
		return maxid;
	}
	else if (choice == 2)
	{
		int maxid = Clients[0].clientId;
		for (int i = 0; i < Clients.size(); i++)
		{
			if (Clients[i].clientId > maxid)
				maxid = Clients[i].clientId;
		}
		return maxid;
	}
	else if (choice == 3)
	{
		int maxid = Vehicles[0].vehicleId;
		for (int i = 0; i < Vehicles.size(); i++)
		{
			if (Vehicles[i].vehicleId > maxid)
				maxid = Vehicles[i].vehicleId;
		}
		return maxid;
	}
}

