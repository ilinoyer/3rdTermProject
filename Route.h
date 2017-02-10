#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include"Date.h"
class Route
{
private:
	int driverId; //identyfikator kierowcy 
	int vehicleId; // identyfikator pojazdu
	int clientId; // identyfikator klienta 
	int kilometers; // liczba przejchanych kilometrów
	std::string routeObject; // cel wyjazdu 
	std::string routeDestination; // miejsce wyjazdu;
	Date date; // data wyjazdu
	
public:
	Route();
	~Route();

	void setRoute();
	void setdate();
	void setKilometers();
	void setObject();
	void setDestination();
	void setDriverId(int);
	void setClientId(int);
	void setVehicleId(int);
	void getRoute();
	void getRouteToMenu();
	friend class DataBaseTxt;
	friend class Data;
	friend void skip(int x);
	bool operator<(const Route& );

};

