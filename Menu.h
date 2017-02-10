#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include"Data.h"
#include "DataBaseTxt.h"
class BaseMenu
{
protected:
	std::string menuText;
public:
	BaseMenu();
	virtual void printText() {
		std::cout << menuText << std::endl;
	}
	virtual ~BaseMenu();
	virtual void loadData() = 0;
	virtual BaseMenu *getNextMenu(char choice, bool& isQuitOptionSelected) = 0; 
};

//----------------------------

class MainMenu : public BaseMenu
{
private :
	std::string menuText;
public:
	MainMenu();
	BaseMenu *getNextMenu(char choice, bool& isQuitOptionSelected);
	void printText();
	void loadData();
	~MainMenu();
};


//--------------------------------------

class ConfMenu : public BaseMenu
{
private:
	std::string menuText;
public:
	ConfMenu();
	BaseMenu *getNextMenu(char choice, bool& isQuitOptionSelected);
	void printText();
	void loadData();
	~ConfMenu();

};

//-------------------------------------

class DriverMenu : public BaseMenu
{
private:
	std::string menuText;
public:
	DriverMenu();
	BaseMenu *getNextMenu(char choice, bool& isQuitOptionSelected);
	void printText();
	void loadData();
	~DriverMenu();

};

//-------------------------------------

class ClientMenu : public BaseMenu
{
private:
	std::string menuText;
public:
	ClientMenu();
	BaseMenu *getNextMenu(char choice, bool& isQuitOptionSelected);
	void printText();
	void loadData();
	~ClientMenu();

};

//------------------------------------

class VehicleMenu : public BaseMenu
{
private:
	std::string menuText;
public:
	VehicleMenu();
	BaseMenu *getNextMenu(char choice, bool& isQuitOptionSelected);
	void printText();
	void loadData();
	~VehicleMenu();

};

//-----------------------------------

class RaportMenu : public BaseMenu
{
private:
	std::string menuText;
public:
	RaportMenu();
	BaseMenu *getNextMenu(char choice, bool& isQuitOptionSelected);
	void printText();
	void loadData();
	~RaportMenu();

};

