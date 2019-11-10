#include "FI.h"

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

FI& FI::operator=(FI& other)
{
	name = other.name;
	ID = other.ID;
	return *this;
}

void FI::setName(string newName) {
	name = newName;
}

void FI::setID(int newID) {
	ID = newID;
}