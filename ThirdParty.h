#pragma once
#ifndef THIRDPARTY_H
#define THIRDPARTY_H

#include <cstdlib>
#include <string>
using namespace std;

//This is the third party header file
//This is meant to contain:
//Name
//ID
//Service Type

class ThirdParty {
private:
	int ID;
	string name;
	string serviceType;

public:
	ThirdParty();
	ThirdParty(int id = 0, string Name = "INVALID NAME", string servicetype = "INVALID SERVICE");

	int getID();
	string getName();
	string getService();
};
#endif //THIRDPARTY_H

ThirdParty::ThirdParty()
{
	ID = 0;
	name = "INVALID NAME";
	serviceType = "INVALID TYPE";
}
ThirdParty::ThirdParty(int id, string Name, string servicetype)
{
	ID = id;
	name = Name;
	serviceType = servicetype;
}

int ThirdParty::getID()
{
	return ID;
}
string ThirdParty::getName()
{
	return name;
}
string ThirdParty::getService()
{
	return serviceType;
}