#pragma once
#include<string>
#include<iostream>
#include<iomanip>
class Vehicle
{
private:
	int vehicleId;
	int type;
	std::string description;
public:
	Vehicle();
	~Vehicle();
	void setVehicle();
	void getVehicle();
	int getId();
	int getType();
	void setId(int);


	friend class DataBaseTxt;
	friend class Data;
};

