#pragma once
class DataBase
{
public:
	DataBase();
	virtual void loadData() = 0;
	virtual void saveData() = 0;
	virtual ~DataBase();
};

