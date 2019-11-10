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


};
#endif FI_H

FI::FI()
{
	name = "INVALID";
	ID = 0;
}
FI::FI(string FIName, int id)
{
	name = FIName;
	ID = id;
}
Report FI::MakeReport(int thirdPartyID, string dueDiligenceDate, string dateOfReport, string reportType) //Make the report
{
	Report report(ID, thirdPartyID, dueDiligenceDate, dateOfReport, reportType); //Calls the parametrized ctor of report in order to make it
	return report;
}
int FI::getID()
{
	return ID;
}
string FI::getName()
{
	return name;
}
