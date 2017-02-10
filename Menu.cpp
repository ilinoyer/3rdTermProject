#include "Menu.h"
#include<string>
//#include "temp.h"
DataBaseTxt dataBase;

extern void error(int, char*);
BaseMenu::BaseMenu()
{
	menuText = " ";
}


BaseMenu::~BaseMenu()
{
}

// ---------------------------------------



//----------------------------------

MainMenu::MainMenu()
{
	
	menuText = "*Menu Glowne*\n"
		+ std::string("[1] Konfiguracja\n") // ok
		+ std::string("[2] Dodaj Przejazd\n") // ok
		+ std::string("[3] Usun Przejazd\n") // ok
		+ std::string("[4] Wyswietl Wszystkie Jazdy\n") // ok
		+ std::string("[5] Posortuj przejazdy\n")// ok
		+ std::string("[6] Zestawienia\n") // ok
		+ std::string("[7] Zapisz\n") // ok
		+ std::string("[8] O programie\n")
		+ std::string("[0] Wyjscie\n"); // ok
}

BaseMenu* MainMenu:: getNextMenu(char choice, bool& isQuitOptionSelected) 
{
	BaseMenu* newMenu = 0;
	
	switch (choice)
	{
	case '1':
		newMenu = new ConfMenu;
		break;
	case '2':
	{
		try {
			int clientId, vehicleId, driverId;
			auto temp = new Route;
			temp->setdate();
			system("cls");
			temp->getRouteToMenu();

			Data::showDrivers();
			std::cout << "Wybierz Id kierowcy: " << std::endl;
			std::cin >> driverId;
			while (Data::checkDriverId(driverId) == 1)
			{
				if (std::cin.fail())
					throw 1;
				std::cout << "Taki kierowca nie istnieje!" << std::endl;
				std::cout << "Wybierz Id kierowcy: " << std::endl;
				std::cin >> driverId;
			}
			
			temp->setDriverId(driverId);
			system("cls");

			temp->getRouteToMenu();
			Data::showClients();
			std::cout << "Wybierz Id klienta: " << std::endl;
			std::cin >> clientId;
			while (Data::checkClientId(clientId) == 1)
			{
				if (std::cin.fail())
					throw 1;
				std::cout << "Taki klient nie istnieje!" << std::endl;
				std::cout << "Wybierz Id klienta: " << std::endl;
				std::cin >> clientId;
			}
			
			temp->setClientId(clientId);
			system("cls");

			temp->getRouteToMenu();
			Data::showVehicles();
			std::cout << "Wybierz Id pojazdu: " << std::endl;
			std::cin >> vehicleId;
			while (Data::checkVehicleId(vehicleId) == 1)
			{
				if (std::cin.fail())
					throw 1;
				std::cout << "Taki pojazd nie istnieje!" << std::endl;
				std::cout << "Wybierz Id pojazdu: " << std::endl;
				std::cin >> vehicleId;
			}
			
			temp->setVehicleId(vehicleId);
			system("cls");
			temp->getRouteToMenu();

			temp->setKilometers();
			system("cls");
			temp->getRouteToMenu();

			temp->setDestination();
			system("cls");
			temp->getRouteToMenu();

			temp->setObject();

			Data::Routes.push_back(*temp);
			system("cls");
			temp->getRouteToMenu();
			delete temp;
			std::cout << "Przejazd dodany! " << std::endl;
			system("pause");
			break;
		}
		catch (...)
		{
			error(1, "Przejazd");
		}
	}
	case '3':
	{
		try {
			system("cls");
			Data::showRoutes();
			size_t i;
			std::cout << "Podaj numer (Lp) elementu do usuniecia:" << std::endl;
			std::cin >> i;
			if (std::cin.fail())
				throw 1;
			if (i - 1 < Data::Routes.size())
			{
				Data::delete_ob(&Data::Routes, i);
				std::cout << "Element usuniety!" << std::endl;
			}
			else
				std::cout << "Zle wprowadzone dane!" << std::endl;

			system("pause");
			break;
		}
		catch (...)
		{
			error(1, "usuwanie przejazdu");
		}
	}
		
	case '4':
		system("cls");
		Data::showRoutes();
		system("pause");
		break;
	
	case '5':
		sort(Data::Routes.begin(), Data::Routes.end());
		break;
	case '6':
		newMenu = new RaportMenu;
		break;
	case '7':
		system("cls");
		dataBase.saveData();
		std::cout << "Zmiany zapisane !" << std::endl;
		system("pause");
		break;
	case '8':
		std::cout << "Witaj w moim programie !\nProgram ten sluzy do zarzadzania mala firma transportowa.\n";
		std::cout << "W menu konfiguracyjnym mamy mozliwosc dodac / usunac / wyswietlic naszych klientow, \nkierowcow czy pojazdy" << std::endl;
		std::cout << "Wszystkie wprowadzone dane po zapisaniu sa przechowywane w plikach tekstowych\ni wczytywane przy ponownym uruchomieniu programu" << std::endl;
		std::cout << "W menu glownym mamy mozliwosc skonfigurowac przejazd wybierajac date, cel wyjazdu,\nmiejsce, kierowce, klienta jak i pojazd jaki wykonal przejazd." << std::endl;
		std::cout << "Rowniez tutaj mozna wyswietlic wszystkie przejazdy, usunac wybrany\nlub posortowac je w tym momecie tylko po dacie." << std::endl;
		std::cout << "Glowna funkcja programu sa opcje ukryte w podmenu 'Zestawienia'. \nW tym submenu mamy do wyboru kilka opcji. " << std::endl;
		std::cout << "Sa one wykonywane na danych wprowadzonych do programu. Kazde zestawienie jest zapisywane w podfolderze Projektu.\nDane w nich sa zapisane w pliku txt oddzielone ';' co u mozliwia latwy eksport do Exela" << std::endl;
		std::cout << "W zamysle program ma na celu przyspieszenie tworzenia miesiecznych zestawien w malej firmie \ntransportowej swiadczacej uslugi dla Stacji Demontarzu Pojazdow"<<std::endl;
		std::cout << "Wszystkie dane wprowadzone w programie zostaly wymyslone w celu jego przetestowania." << std::endl;
		system("pause");
		break;
	case '0':
		isQuitOptionSelected = true;
		break;
	default:
	{
		
	}

	}

	return newMenu;
}

void MainMenu::loadData()
{
	dataBase.loadData();
}

void MainMenu:: printText()
{
	system("cls");
	std::cout << menuText << std::endl;
}
MainMenu::~MainMenu()
{

}

//----------------------------------

ConfMenu::ConfMenu()
{
	menuText = "Menu Konfiguracyjne\n"
		+ std::string("[1] Kierowcy\n")  // ok
		+ std::string("[2] Klienci\n")	// ok
		+ std::string("[3] Pojazdy\n")	// ok
		+ std::string("[0] Powrot\n");	// ok
}

BaseMenu* ConfMenu::getNextMenu(char choice, bool& isQuitOptionSelected)
{
	BaseMenu* newMenu = 0;
	switch (choice)
	{
	case '1':
		newMenu = new DriverMenu;
		break;
	case '2':
		newMenu = new ClientMenu;
		break;
	case '3':
		newMenu = new VehicleMenu;
		break;
	case '0':
		newMenu = new MainMenu;
		break;
	default:
	{

	}
	}

	return newMenu;
}

void ConfMenu::printText()
{
	system("cls");
	std::cout << menuText << std::endl;
}
void ConfMenu::loadData()
{
	dataBase.loadData();
}

ConfMenu::~ConfMenu()
{

}

//-------------------------------

DriverMenu::DriverMenu()
{
	menuText = "Menu Konfiguracyjne\n"
		+ std::string("[1] Dodaj Kierowce\n") // ok
		+ std::string("[2] Usun Kierowce\n") // ok
		+ std::string("[3] Wyswietl Kierowcow\n") // ok
		+ std::string("[4] Zapisz\n") // ok
		+ std::string("[0] Powrot\n"); // ok
}

BaseMenu* DriverMenu::getNextMenu(char choice, bool& isQuitOptionSelected)
{
	BaseMenu* newMenu = 0;
	switch (choice)
	{
	case '1':
	{
		auto temp = new Driver; 
		temp->setDriver();
		int check = temp->getId();
		if(Data::checkDriverId(check) == 0)
		{
			std::cout << "Kierowca o tym Id juz istnieje! " << std::endl;
			int id = Data::getMaxId(1) + 1;
			std::cout << "Automatycznie przydzielone id tego kierowcy to :" << id << std::endl;
			temp->setId(id);
		}
		Data::Drivers.push_back(*temp);
		std::cout << "Kierowca dodany!" << std::endl;
		delete temp;
		system("pause");
		break;
	}
	case '2':
	{
		try {
			system("cls");
			Data::showDrivers();
			size_t i;
			std::cout << "Podaj numer (Lp) elementu do usuniecia:" << std::endl;
			std::cin >> i;
			if (std::cin.fail())
				throw 1;
			if (i - 1 < Data::Drivers.size())
			{
				Data::delete_ob(&Data::Drivers, i);
				std::cout << "Element usuniety!" << std::endl;
			}
			else
				std::cout << "Zle wprowadzone dane !" << std::endl;
			system("pause");
			break;
		}
		catch (...)
		{
			error(1, "usuwanie kierowcy");
		}
	}
	case '3':
		system("cls");
		Data::showDrivers();
		system("pause");
		break;
	case '4':
		system("cls");
		dataBase.saveDrivers();
		std::cout << "Zmiany zapisane !" << std::endl;
		system("pause");
		break;
	case '0':
		newMenu = new ConfMenu;
		break;
	default:
	{

	}
	}

	return newMenu;
}

void DriverMenu::printText()
{
	system("cls");
	std::cout << menuText << std::endl;
}

void DriverMenu::loadData()
{
	dataBase.loadData();
}

DriverMenu::~DriverMenu()
{

}

//---------------------------------------

ClientMenu::ClientMenu()
{
	menuText = "Menu Konfiguracyjne\n"
		+ std::string("[1] Dodaj Klienta\n") // ok
		+ std::string("[2] Usun Klienta\n") // ok
		+ std::string("[3] Wyswietl Klientow\n") // ok
		+ std::string("[4] Zapisz\n") // ok
		+ std::string("[0] Powrot\n"); // ok
}

BaseMenu* ClientMenu::getNextMenu(char choice, bool& isQuitOptionSelected)
{
	BaseMenu* newMenu = 0;
	switch (choice)
	{
	case '1':
	{
		auto temp = new Client;
		temp->setClient();
		int check = temp->getId();
		if (Data::checkClientId(check) == 0)
		{
			std::cout << "Klient o tym Id juz istnieje! " << std::endl;
			int id = Data::getMaxId(2) + 1;
			std::cout << "Automatycznie przydzielone id tego klienta to :" << id << std::endl;
			temp->setId(id);
		}
		Data::Clients.push_back(*temp);
		std::cout << "Klient dodany!" << std::endl;
		delete temp;
		system("pause");
		break;
	}
	case '2': 
	{
		try {
			system("cls");
			Data::showClients();
			size_t i;
			std::cout << "Podaj numer (Lp) elementu do usuniecia:" << std::endl;
			std::cin >> i;
			if (std::cin.fail())
				throw 1;
			if (i - 1 < Data::Clients.size())
			{
				Data::delete_ob(&Data::Clients, i);
				std::cout << "Element usuniety!" << std::endl;
			}
			else
				std::cout << "Zle wprowadzone dane !" << std::endl;
			system("pause");
			break;
		}
		catch (...)
		{
			error(1, "usuwanie klienta");
		}
	}
		
	case '3':
		system("cls");
		Data::showClients();
		system("pause");
		break;
	case '4':
		system("cls");
		dataBase.saveClients();
		std::cout << "Zmiany zapisane !" << std::endl;
		system("pause");
		break;
	case '0':
		newMenu = new ConfMenu;
		break;
	default:
	{

	}
	}

	return newMenu;
}

void ClientMenu::printText()
{
	system("cls");
	std::cout << menuText << std::endl;
}

void ClientMenu::loadData()
{
	dataBase.loadData();
}

ClientMenu::~ClientMenu()
{

}


//---------------------------------------

VehicleMenu::VehicleMenu()
{
	menuText = "Menu Konfiguracyjne\n"
		+ std::string("[1] Dodaj Pojazd\n") // ok
		+ std::string("[2] Usun Pojazd\n") // ok
		+ std::string("[3] Wyswietl Pojazdy\n") // ok
		+ std::string("[4] Zapisz\n") // ok
		+ std::string("[0] Powrot\n");
}

BaseMenu* VehicleMenu::getNextMenu(char choice, bool& isQuitOptionSelected)
{
	BaseMenu* newMenu = 0;
	switch (choice)
	{
	case '1':
	{
		auto temp = new Vehicle;
		temp->setVehicle();
		int check = temp->getId();
		if (Data::checkVehicleId(check) == 0)
		{
			std::cout << "Pojazd o tym Id juz istnieje! " << std::endl;
			int id = Data::getMaxId(3) + 1;
			std::cout << "Automatycznie przydzielone id tego pojazdu to :" << id << std::endl;
			temp->setId(id);
		}
		Data::Vehicles.push_back(*temp);
		std::cout << "Pojazd dodany!" << std::endl;
		delete temp;
		system("pause");
		break;
	}
	case '2':
	{
		try {
			system("cls");
			Data::showVehicles();
			size_t i;
			std::cout << "Podaj numer (Lp) elementu do usuniecia:" << std::endl;
			std::cin >> i;
			if (std::cin.fail())
				throw 1;
			if (i - 1 < Data::Vehicles.size())
			{
				Data::delete_ob(&Data::Vehicles, i);
				std::cout << "Element usuniety!" << std::endl;
			}
			else
				std::cout << "Zle wprowadzone dane !" << std::endl;
			system("pause");
			break;
		}
		catch (...)
		{
			error(1, "usuwanie klienta");
		}
	}
		
	case '3':
		system("cls");
		Data::showVehicles();
		system("pause");
		break;
	case '4':
		system("cls");
		dataBase.saveVehicles();
		std::cout << "Zmiany zapisane !" << std::endl;
		system("pause");
		break;
	case '0':
		newMenu = new ConfMenu;
		break;
	default:
	{

	}
	}

	return newMenu;
}

void VehicleMenu::printText()
{
	system("cls");
	std::cout << menuText << std::endl;
}


void VehicleMenu::loadData()
{
	dataBase.loadData();
}

VehicleMenu::~VehicleMenu()
{

}

//--------------------------------------------


RaportMenu::RaportMenu()
{
	menuText = "Wybierz ktore zestawienie chcesz stworzyc:\n"
		+ std::string("[1] Podsumowanie miesieczne dla kazdego pojazdu.\n") // ok
		+ std::string("[2] Podsumowanie miesieczne dla kazdego klienta.\n") //  ok 
		+ std::string("[3] Podsumowanie miesieczne dla kazdego pojazdu wzgledem klientow.\n") //  ok
		+ std::string("[4] Podsumowanie miesiaca pracownikow.\n") // ok
		+ std::string("[5] Wstepne rozliczenie miesieczne klientow.\n") //  ok 
		+ std::string("[6] Opis zestawien.\n")
		+ std::string("[0] Powrot\n");
}


BaseMenu* RaportMenu::getNextMenu(char choice, bool& isQuitOptionSelected)
{
	BaseMenu* newMenu = 0;
	switch (choice)
	{
	case '1':
	{
		try {
			int year, month;
			system("cls");
			std::cout << "Wybrano zestawienie miesieczne dla kazdego pojazdu." << std::endl;
			std::cout << "Podaj rok: " << std::endl;
			std::cin >> year;
			std::cout << "Podaj miesiac: " << std::endl;
			std::cin >> month;
			if (std::cin.fail())
				throw 1;
			dataBase.monthlyVehicleRaport(year, month);

			break;
		}
		catch (...)
		{
			error(1, "zestawienie 1");
		}
	}
	case '2':
	{
		try {
			int year, month;
			system("cls");
			std::cout << "Wybrano zestawienie miesieczne dla kazdego klienta./n" << std::endl;
			std::cout << "Podaj rok: " << std::endl;
			std::cin >> year;
			std::cout << "Podaj miesiac: " << std::endl;
			std::cin >> month;
			if (std::cin.fail())
				throw 1;
			dataBase.monthlyClientRaport(year, month);
			break;
		}
		catch(...)
		{
			error(1, "zestawienie 2");
		}
	}

	case '3':
	{
		try {
			int year, month;
			system("cls");
			std::cout << "Wybrano zestawienie miesieczne dla kazdego pojazdu z uwzglednieniem klientow.\n" << std::endl;
			std::cout << "Podaj rok: " << std::endl;
			std::cin >> year;
			std::cout << "Podaj miesiac: " << std::endl;
			std::cin >> month;
			if (std::cin.fail())
				throw 1;
			dataBase.mothlyRoutesForClients(year, month);
		}
		catch (...)
		{
			error(1, "zestawienie 3");
		}
	}
		break;
	case '4':
	{
		try {
			int year, month;
			system("cls");
			std::cout << "Wybrano podsumowanie miesiaca pracownikow.\n " << std::endl;
			std::cout << "Podaj rok: " << std::endl;
			std::cin >> year;
			std::cout << "Podaj miesiac: " << std::endl;
			std::cin >> month;
			if (std::cin.fail())
				throw 1;
			dataBase.monthlyDriversRaport(year, month);
		}
		catch (...)
		{
			error(1, "zestawienie 4");
		}
	}
	case '5':
	{
		try {
			int year, month;
			system("cls");
			std::cout << "Wybrano wstepne rozliczenie miesieczne klientow." << std::endl;
			std::cout << "Podaj rok: " << std::endl;
			std::cin >> year;
			std::cout << "Podaj miesiac: " << std::endl;
			std::cin >> month;
			if (std::cin.fail())
				throw 1;
			dataBase.monthlyInvoiceForClients(year, month);
		}
		catch (...)
		{
			error(1, "zestawienie 4");
		}
	}
		break;
	case '6':
	{
		std::cout << "[1] Podsumowanie miesieczne dla kazdego pojazdu.\n";
		std::cout << "Podsumowanie generuje plik dla kazdego pojazdu z przejazdami wykonanymi przez pojazd oraz jeden plik z podsumowanymi KM.\n\n";
		std::cout << "[2] Podsumowanie miesieczne dla kazdego klienta.\n";
		std::cout << "Podsumowanie generuje plik dla kazdego klienta z przejazdami zapisanymi na jego konto oraz jeden plik z podliczonymi KM.\n\n";
		std::cout << "[3] Podsumowanie miesieczne dla kazdego pojazdu wzgledem klientow.\n";
		std::cout << "Podsumowanie generuje dla kazdego klienta plik z kazdego samochodu. Jest to rozszezenie podsumowania [2]. Jest konieczne ze wzgledu na typy pojazdow.\n\n";
		std::cout << "[4] Podsumowanie miesiaca pracownikow.\n";
		std::cout << "Podsumowanie generuje plik dla kazdego pracownika z przejazdami zapisanymi na jego konto oraz jeden plik z podliczonymi KM\n\n";
		std::cout << "[5] Wstepne rozliczenie miesieczne klientow.\n";
		std::cout << "Rozliczenie generuje plik dla kazdego klienta. W nim znajduje sie tableka z przejchanymi KM o raz wstepne rozliczenie miesieczne.\n\n";
		std::cout << "Pliki zostana zapisane w podfolderze w folderze glownym projektu. Nazwa podfolderu wedlug wzoru [rok][miesiac]. \nNazwy plikow zaczynaja sie od numeru zestawienia.";
		system("pause");
		break;
	}
	case '0':
		newMenu = new MainMenu;
		break;
	default:
	{

	}
	}

	return newMenu;
}

void RaportMenu::printText()
{
	system("cls");
	std::cout << menuText << std::endl;
}

RaportMenu::~RaportMenu()
{

}


void RaportMenu::loadData()
{
	dataBase.loadData();
}