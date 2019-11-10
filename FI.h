#pragma once
#ifndef FI_H
#define FI_H

#include <cstdlib>
#include <string>
#include "Report.h"

using namespace std;

//This is the financial institution header file
//This is meant to store the following:
//Name
//ID
//Make a report (and connect it to the blockchain)

class FI {
private:
	string name;
	int ID;

public:
	FI();
	FI(string FIName, int id);
	Report MakeReport(int thirdPartyID, string dueDiligenceDate, string dateOfReport, string reportType); //Make the report

	int getID();
	string getName();
	FI& operator=(FI& other);
	void setName(string);
	void setID(int);
};
#endif FI_H
