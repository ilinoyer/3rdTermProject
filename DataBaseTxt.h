#pragma once
#include "DataBase.h"
#include "Data.h"
#include<string>
#include"Driver.h"
#include <cstdlib>
class DataBaseTxt :
	public DataBase
{
private:
	
public:
	DataBaseTxt();
	void loadData();
	void saveData();
	void saveDrivers();
	void saveClients();
	void saveVehicles();
	void monthlyVehicleRaport(int, int);
	void monthlyDriversRaport(int, int);
	void monthlyClientRaport(int, int);
	void mothlyRoutesForClients(int, int);
	void monthlyInvoiceForClients(int, int);
	//void writeRoutes(std::fstream&, std::vector<Route>*);
	friend void skip(int x);
	static wchar_t *convertCharArrayToLPCWSTR(const char*);
	~DataBaseTxt();
};

