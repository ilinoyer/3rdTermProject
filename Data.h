#pragma once
#include<vector>
#include<fstream>
#include<Windows.h>
#include "Client.h"
#include "Driver.h"
#include "Route.h"
#include "Vehicle.h"

#include<iomanip>
class Data
{
private:
	
	Data();
public:
	
	static std::vector <Client> Clients;
	static std::vector <Route> Routes;
	static std::vector <Vehicle> Vehicles;
	static std::vector <Driver> Drivers;
	~Data();
	static void showDrivers();
	static void showClients();
	static void showVehicles();
	static void showRoutes();
	static bool checkDriverId(int);
	static int getMaxId(int);
	static bool checkClientId(int);
	static bool checkVehicleId(int);
	friend void skip(int x);
	
	template <typename T> static void delete_ob(static std::vector<T> *a, int b) {
		a->erase(a->begin() + b - 1);
	}

};




