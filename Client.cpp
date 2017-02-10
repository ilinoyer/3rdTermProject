//#include<isotream>
//#include<string>
#include "Client.h"


extern void error(int, char*);



Client::Client()
{
}


Client::~Client()
{
}

Client::Client(std::string _companyName, int _clientId)
{
	clientId = _clientId;
	companyName = _companyName;
}


void Client::setClient()
{
	try {
		std::cout << "Podaj identyfikator klienta:" << std::endl;
		std::cin >> clientId;
		if (std::cin.fail())
			throw 1;
		std::cout << "Podaj nazwe klienta:" << std::endl;
		std::cin >> companyName;
	}
	catch (...)
	{
		error(1, "set client");
	}
}


void Client::getClient()
{
	std::cout << std::setw(4) << clientId << "   " << companyName << std::endl;
}

int Client::getId()
{
	return clientId;
}

void Client::setId(int Id)
{
	clientId = Id;
}
