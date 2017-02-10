// Projekt.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include<vector>
#include<Windows.h>
#include<conio.h>
#include "Client.h"
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"
#include "Data.h"
#include "DataBaseTxt.h"
#include "DataBase.h"
#include"Menu.h"

using namespace std;

std::vector <Client> Data::Clients;
std::vector <Driver> Data::Drivers;
std::vector <Route> Data::Routes;
std::vector <Vehicle> Data::Vehicles;






int main()
{
	
	BaseMenu* CurrentMenu = new MainMenu;
	CurrentMenu->loadData();
	bool isQuitOptionSelected = false;
	while (!isQuitOptionSelected)
	{
		CurrentMenu->printText();

		char choice=getch();
		
		BaseMenu* aNewMenuPointer = CurrentMenu->getNextMenu(choice, isQuitOptionSelected);

		if (aNewMenuPointer)
		{
			delete CurrentMenu;
			CurrentMenu = aNewMenuPointer;
		}
	}
	

	


		return 0;
}


void skip(int x)
{
	
	for (int i = 0; i < x; i++)
		std::cout << " ";
}