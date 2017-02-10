#pragma once
#include<string>
#include<iostream>
#include<iomanip>

class Client
{
private:
	int clientId;
	std::string companyName;

public:
	Client(std::string , int);
	Client();
	~Client();
	void setClient();
	void getClient();
	int getId();
	void setId(int);

	friend class DataBaseTxt;
	friend class Data;
};

