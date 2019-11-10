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
	ThirdParty(int id, string Name, string servicetype);

	int getID();
	string getName();
	string getService();
};
#endif //THIRDPARTY_H

