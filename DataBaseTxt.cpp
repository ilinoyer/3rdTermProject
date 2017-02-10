#include "DataBaseTxt.h"
#include<fstream>
#include<iostream>
#include<string>

extern void error(int, char*);


DataBaseTxt::DataBaseTxt()
{
}


DataBaseTxt::~DataBaseTxt()
{
}






void DataBaseTxt::saveDrivers()
{
	std::fstream Drivers;    // zapisywanie kierowców do pliku 
	Drivers.open("Drivers.txt", std::ios::out);
	if (Drivers.good() == true)
	{
		int j = Data::Drivers.size();
		for (int i = 0; i < j; i++)
		{
			Drivers << Data::Drivers[i].driverId << ";" << Data::Drivers[i].firstName << ";" << Data::Drivers[i].lastName;
			if (i != j - 1)
				Drivers << std::endl;
		}
		Drivers.close();
	}
	else
		error(2, "Plik Kierowcy");
	
}


void DataBaseTxt::saveClients()
{

	std::fstream Clients; // zapisywanie klientów do pliku 
	Clients.open("Clients.txt", std::ios::out);
	if (Clients.good() == true)
	{
		int j = Data::Clients.size();
		for (int i = 0; i < j; i++)
		{
			Clients << Data::Clients[i].clientId << ";" << Data::Clients[i].companyName;
			if (i != j - 1)
				Clients << std::endl;
		}
		Clients.close();
	}
	else
		error(2, "Plik Klienci");
	
}


void DataBaseTxt::saveVehicles()
{

	std::fstream Vehicles; // zapisywanie pojazdów do pliku 
	Vehicles.open("Vehicles.txt", std::ios::out);
	if (Vehicles.good() == true)
	{
		int j = Data::Vehicles.size();
		for (int i = 0; i < j; i++)
		{
			Vehicles << Data::Vehicles[i].vehicleId << ";" << Data::Vehicles[i].type << ";" << Data::Vehicles[i].description;
			
			if (i != j - 1)
				Vehicles << std::endl;
		}
		Vehicles.close();
	}
	else
		error(2, "Plik Pojazdy");

}

void DataBaseTxt::saveData()
{
	saveDrivers();
	saveClients();
	saveVehicles();
	
	std::fstream Routes; // zapisywanie przejazdów do pliku 
	Routes.open("Routes.txt", std::ios::out);
	if (Routes.good() == true)
	{
		int j = Data::Routes.size();
		for (int i = 0; i < j; i++)
		{
			
			Routes << Data::Routes[i].driverId << ";" << Data::Routes[i].vehicleId << ";"
				<< Data::Routes[i].clientId << ";" << Data::Routes[i].kilometers << ";"
				<< Data::Routes[i].date.day << ";" << Data::Routes[i].date.month << ";"
				<< Data::Routes[i].date.year << ";" << Data::Routes[i].routeObject << ";"
				<< Data::Routes[i].routeDestination;
			
			if (i != j - 1)
				Routes << std::endl;
			
		}
		Routes.close();
	}
	else
		error(2, "Plik Przejazdy");
	

}


void DataBaseTxt::loadData()
{
	
	std::fstream Drivers;  // wczytywanie kierowców 
	Drivers.open("Drivers.txt", std::ios::in);
	if (Drivers.good() == true)
	{
		std::string bufor;
		while (!(Drivers.eof()))
		{
			auto temp = new Driver;
			std::getline(Drivers, bufor, ';');
			temp->driverId = std::atoi(bufor.c_str());
			std::getline(Drivers, bufor, ';');
			temp->firstName = bufor;
			std::getline(Drivers, bufor);
			temp->lastName = bufor;
			Data::Drivers.push_back(*temp);
			delete temp;
		}
		Drivers.close();
	}
	else
		error(2, "Plik Kierowcy");
	

	std::fstream Clients; // wczytywanie klientów
	Clients.open("Clients.txt", std::ios::in);
	if (Clients.good() == true)
	{
		std::string bufor;
		while (!(Clients.eof()))
		{
			auto temp = new Client;
			std::getline(Clients, bufor, ';');
			temp->clientId = std::atoi(bufor.c_str());
			std::getline(Clients, bufor);
			temp->companyName = bufor;
			Data::Clients.push_back(*temp);
			delete temp;
		}
		Clients.close();
	}
	else
		error(2, "Plik Przejazdy");
	


	std::fstream Vehicles; // wczytywanie pojazdów
	Vehicles.open("Vehicles.txt", std::ios::in);
	if (Vehicles.good() == true)
	{
		std::string bufor;
		while (!(Vehicles.eof()))
		{
			auto temp = new Vehicle;
			std::getline(Vehicles, bufor, ';');
			temp->vehicleId = std::atoi(bufor.c_str());
			std::getline(Vehicles, bufor, ';');
			temp->type = std::atoi(bufor.c_str());
			std::getline(Vehicles, bufor);
			temp->description = bufor;
			Data::Vehicles.push_back(*temp);
			delete temp;
		}
		Vehicles.close();
	}
	else
		error(2, "Plik Przejazdy");
	

	std::fstream Routes; // wczytywanie przejazdów
	Routes.open("Routes.txt", std::ios::in);
	if (Routes.good() == true)
	{
		std::string bufor;
		while (!(Routes.eof()))
		{
			auto temp = new Route;
			std::getline(Routes, bufor, ';');
			temp->driverId = std::atoi(bufor.c_str());
			std::getline(Routes, bufor, ';');
			temp->vehicleId = std::atoi(bufor.c_str());
			std::getline(Routes, bufor, ';');
			temp->clientId = std::atoi(bufor.c_str());
			std::getline(Routes, bufor, ';');
			temp->kilometers = std::atoi(bufor.c_str());
			std::getline(Routes, bufor, ';');
			temp->date.day = std::atoi(bufor.c_str());
			std::getline(Routes, bufor, ';');
			temp->date.month = std::atoi(bufor.c_str());
			std::getline(Routes, bufor, ';');
			temp->date.year = std::atoi(bufor.c_str());
			std::getline(Routes, bufor, ';');
			temp->routeObject = bufor;
			std::getline(Routes, bufor);
			temp->routeDestination = bufor;
			Data::Routes.push_back(*temp);
			delete temp;
		}
		Routes.close();
	}
	else
		error(2, "Plik Przejazdy");
	
}


void DataBaseTxt::monthlyVehicleRaport(int year, int month)
{
	std::vector<Route> routesToSave;
	double kilometersSum = 0;
	std::string dirName = "Raport" + std::to_string(year) + std::to_string(month);
	LPCWSTR name = convertCharArrayToLPCWSTR(dirName.c_str());

	CreateDirectory(name, NULL);

	for (size_t  i = 0; i < Data::Vehicles.size(); i++)
	{
		for (size_t  j = 0; j < Data::Routes.size(); j++)
		{
			if (year == Data::Routes[j].date.getyear() && month == Data::Routes[j].date.getmonth() && Data::Vehicles[i].getId() == Data::Routes[j].vehicleId)
			{
				routesToSave.push_back(Data::Routes[j]);
				kilometersSum += Data::Routes[j].kilometers;
			}
		}
		std::string fileName = dirName + "\\PojazdId" + std::to_string(Data::Vehicles[i].getId()) + std::string(".txt");
		std::fstream file;
		file.open(fileName.c_str(), std::ios::out);
		if (file.good() == true)
		{
			for (size_t  k = 0; k < routesToSave.size(); k++)
			{
				file << routesToSave[k].driverId << ";" << routesToSave[k].vehicleId << ";"
					<< routesToSave[k].clientId << ";" << routesToSave[k].kilometers << ";"
					<< routesToSave[k].date.getday() << ";" << routesToSave[k].date.getmonth() << ";"
					<< routesToSave[k].date.getyear() << ";" << routesToSave[k].routeObject << ";"
					<< routesToSave[k].routeDestination << std::endl;
			}
			file.close();
		}
		else
			error(2, "Rap1");
		
		routesToSave.erase(routesToSave.begin(), routesToSave.end());

		std::string rapName = dirName + "//RaportZbiorczyPojazdow.txt";
		std::fstream raport;
		raport.open(rapName.c_str(), std::ios::app);
		if (raport.good() == true)
		{
			raport << Data::Vehicles[i].vehicleId << ";" << Data::Vehicles[i].description << "   " << kilometersSum << "KM\n" << std::endl;
			raport.close();
		}
		else
			error(2, "Rap1");
		
		kilometersSum = 0;
	}
}


void DataBaseTxt::monthlyDriversRaport(int year, int month)
{
	std::string dirName = "Raport" + std::to_string(year) + std::to_string(month);
	LPCWSTR name = convertCharArrayToLPCWSTR(dirName.c_str());

	CreateDirectory(name, NULL);

	std::vector <Route> routesToSave;
	double kilometersSum = 0;
	for (size_t  i = 0; i < Data::Drivers.size(); i++)
	{
		for (size_t j = 0; j < Data::Routes.size(); j++)
		{
			if (year == Data::Routes[j].date.getyear() && month == Data::Routes[j].date.getmonth() && Data::Drivers[i].getId() == Data::Routes[j].driverId)
			{
				routesToSave.push_back(Data::Routes[j]);
				kilometersSum += Data::Routes[j].kilometers;
			}

		}


		std::string fileName = dirName + "\\KierowcaId" + std::to_string(Data::Drivers[i].getId()) + std::string(".txt");
		std::fstream file;
		file.open(fileName.c_str(), std::ios::out);
		if (file.good() == true)
		{
			for (size_t  k = 0; k < routesToSave.size(); k++)
			{
				file << routesToSave[k].driverId << ";" << routesToSave[k].vehicleId << ";"
					<< routesToSave[k].clientId << ";" << routesToSave[k].kilometers << ";"
					<< routesToSave[k].date.getday() << ";" << routesToSave[k].date.getmonth() << ";"
					<< routesToSave[k].date.getyear() << ";" << routesToSave[k].routeObject << ";"
					<< routesToSave[k].routeDestination << std::endl;
			}
			file.close();
		}
		else
			error(2, "Rap2");

		routesToSave.erase(routesToSave.begin(), routesToSave.end());


		std::string rapName = dirName + "//RaportZbiorczyKierowcy.txt";
		std::fstream raport;
		raport.open(rapName.c_str(), std::ios::app);
		if (raport.good() == true)
		{
			raport << Data::Drivers[i].driverId << ";" << Data::Drivers[i].firstName << ";" << Data::Drivers[i].lastName << "   " << kilometersSum << "KM\n" << std::endl;
			raport.close();
		}
		else
			error(2, "Rap2");
		kilometersSum = 0;
	}

}


void DataBaseTxt::monthlyClientRaport(int year, int month)
{
	std::string dirName = "Raport" + std::to_string(year) + std::to_string(month);
	LPCWSTR name = convertCharArrayToLPCWSTR(dirName.c_str());

	CreateDirectory(name, NULL);

	std::vector <Route> routesToSave;
	double kilometersSum = 0;

	for (size_t i= 0; i < Data::Clients.size(); i++)
	{
		for (size_t  j = 0; j < Data::Routes.size(); j++)
		{
			if (year == Data::Routes[j].date.getyear() && month == Data::Routes[j].date.getmonth() && Data::Clients[i].getId() == Data::Routes[j].clientId)
			{
				routesToSave.push_back(Data::Routes[j]);
				kilometersSum += Data::Routes[j].kilometers;
			}
		}

		std::string fileName = dirName + "\\KlientId" + std::to_string(Data::Clients[i].getId()) + std::string(".txt");
		std::fstream file;
		file.open(fileName.c_str(), std::ios::out);
		if (file.good() == true)
		{
			for (size_t  k = 0; k < routesToSave.size(); k++)
			{
				file << routesToSave[k].driverId << ";" << routesToSave[k].vehicleId << ";"
					<< routesToSave[k].clientId << ";" << routesToSave[k].kilometers << ";"
					<< routesToSave[k].date.getday() << ";" << routesToSave[k].date.getmonth() << ";"
					<< routesToSave[k].date.getyear() << ";" << routesToSave[k].routeObject << ";"
					<< routesToSave[k].routeDestination << std::endl;
			}
			file.close();
		}
		else
			error(2, "Rap3");
		
		routesToSave.erase(routesToSave.begin(), routesToSave.end());


		std::string rapName = dirName + "//RaportZbiorczyKKlienci.txt";
		std::fstream raport;
		raport.open(rapName.c_str(), std::ios::app);
		if (raport.good() == true)
		{
			raport << Data::Clients[i].clientId << ";" << Data::Clients[i].companyName << "   " << kilometersSum << "KM\n" << std::endl;
			raport.close();
		}
		else
			error(2, "Rap3");
		kilometersSum = 0;
	}

}

void DataBaseTxt::mothlyRoutesForClients(int year, int month)
{
	std::string dirName = "Raport" + std::to_string(year) + std::to_string(month);
	LPCWSTR name = convertCharArrayToLPCWSTR(dirName.c_str());

	CreateDirectory(name, NULL);

	std::vector <Route> routesToSave;
	double kilometersSum = 0;

	for (size_t  i = 0; i < Data::Clients.size(); i++)
	{
		for (size_t  j = 0; j < Data::Vehicles.size(); j++)
		{
			for (size_t  k = 0; k < Data::Routes.size(); k++)
			{
				if (year == Data::Routes[k].date.getyear() && month == Data::Routes[k].date.getmonth()
					&& Data::Clients[i].getId() == Data::Routes[k].clientId &&  Data::Routes[k].vehicleId == Data::Vehicles[j].getId())
				{
					routesToSave.push_back(Data::Routes[k]);
					kilometersSum += Data::Routes[k].kilometers;
				}
			}

			std::string fileName = dirName + "\\KlientId" + std::to_string(Data::Clients[i].getId()) + "VehicleId" +
				std::to_string(Data::Vehicles[j].getId()) + std::string(".txt");
			std::fstream file;
			file.open(fileName.c_str(), std::ios::out);
			if (file.good() == true)
			{
				for (size_t  l = 0; l < routesToSave.size(); l++)
				{
					file << routesToSave[l].driverId << ";" << routesToSave[l].vehicleId << ";"
						<< routesToSave[l].clientId << ";" << routesToSave[l].kilometers << ";"
						<< routesToSave[l].date.getday() << ";" << routesToSave[l].date.getmonth() << ";"
						<< routesToSave[l].date.getyear() << ";" << routesToSave[l].routeObject << ";"
						<< routesToSave[l].routeDestination << std::endl;
				}
				file.close();
			}
			else
				error(2, "Rap4");
			
			routesToSave.erase(routesToSave.begin(), routesToSave.end());
		}
	}



}


void DataBaseTxt::monthlyInvoiceForClients(int year, int month)
{
	std::string dirName = "Raport" + std::to_string(year) + std::to_string(month);
	LPCWSTR name = convertCharArrayToLPCWSTR(dirName.c_str());

	CreateDirectory(name, NULL);
	double kilometerst_1 = 0;
	double kilometerst_2 = 0;
	double kilometerst_3 = 0;

	for (size_t i = 0; i < Data::Clients.size(); i++)
	{
		for (size_t k = 0; k < Data::Routes.size(); k++)
		{
			for (size_t j = 0; j < Data::Vehicles.size(); j++)
			{
				if (year == Data::Routes[k].date.getyear() && month == Data::Routes[k].date.getmonth() && Data::Clients[i].getId() == Data::Routes[k].clientId && Data::Routes[k].vehicleId == Data::Vehicles[j].getId())
				{
					switch (Data::Vehicles[j].getType())
					{
					case 1:
						kilometerst_1 += Data::Routes[k].kilometers;
						break;
					case 2:
						kilometerst_2 += Data::Routes[k].kilometers;
						break;
					case 3:
						kilometerst_3 += Data::Routes[k].kilometers;
						break;
					default:
						break;
					}
				}
			}
		}
		double worth1 = kilometerst_1 * 2.2;
		double worth2 = kilometerst_2 * 3.5;
		double worth3 = kilometerst_3 * 4.5;
		double sum = worth1 + worth2 + worth3;
		std::string fileName = dirName + "\\RozliczenieKlientId" + std::to_string(Data::Clients[i].getId()) + std::string(".txt");
		std::fstream file;
		file.open(fileName.c_str(), std::ios::out);
		if (file.good() == true)
		{
			file << "==============================\n"
				<< "|Wstepne podsumowanie " << year << "-" << std::setw(2) << month << "|\n"
				<< "==============================\n\n\n"
				<< "===========================================\n"
				<< "| Typ pojazdu | Ilosc KM | Cena | Wartosc |\n"
				<< "===========================================\n"
				<< "| DMC < 3,5Mg | " << std::setw(8) << kilometerst_1 << " |  2,20| " << std::setw(8) << worth1 << "|\n"
				<< "===========================================\n"
				<< "| DMC < 6,5Mg | " << std::setw(8) << kilometerst_2 << " |  3,50| " << std::setw(8) << worth2 << "|\n"
				<< "===========================================\n"
				<< "| DMC > 6,5Mg | " << std::setw(8) << kilometerst_3 << " |  4,50| " << std::setw(8) << worth3 << "|\n"
				<< "===========================================\n"
				<< "| SUMA  " << std::setw(34) << sum << "|\n"
				<< "===========================================\n";
			file.close();
		}
		else
			error(2, "Rap5");

		kilometerst_1 = 0;
		kilometerst_2 = 0;
		kilometerst_3 = 0;
	}

}







wchar_t* DataBaseTxt::convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

