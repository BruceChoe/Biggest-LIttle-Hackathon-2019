#pragma once
#ifndef REPORT_H
#define REPORT_H

#include <cstdlib>
#include <memory>
#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

//This is the report header file
//This is meant to track the different due diligence reports made by financial institutions onto third party institutions
//This contains:
//FI ID (that made the report)
//Third party ID (that the report was about)
//Due diligence File
//Completion date of due diligence
//Completion date of report
//Due diligence type (accounting, HR, IT, etc...)
//

class Report {
private:

	int FI_ID;
	int ThirdParty_ID;

	string duediligenceDate;
	string reportDate;
	string duediligenceType;

public:

	Report();
	Report(int fi_id, int thirdparty_id, string duediligencedate, string reportdate, string duediligencetype);
	Report& operator=(Report& other);
	Report(Report& other);
	//Setters and getters may be implemented in the future - yet if a FI wants to be created it should only be done through the parametrized ctor
	void printReport(ostream& os);

	//string getFIName();
	//string getThirdPartyName(); Maybe later? 

};
#endif //REPORT_H

Report::Report()
{
	FI_ID = 0;
	ThirdParty_ID = 0;
	duediligenceDate = "INVALID DATE";
	reportDate = "INVALID DATE";
	duediligenceType = "INVALID TYPE";
	//Sets everything to invalid
}

Report::Report(int fi_id, int thirdparty_id, string duediligencedate, string reportdate, string duediligencetype)
	: FI_ID(fi_id), ThirdParty_ID(thirdparty_id), duediligenceDate("Empty"), reportDate("empty"), duediligenceType("Empty)")
{
}

Report& Report::operator=(Report& other)
{
	FI_ID = other.FI_ID;
	ThirdParty_ID = other.ThirdParty_ID;
	duediligenceDate = other.duediligenceDate;
	reportDate = other.reportDate;
	duediligenceType = other.duediligenceType;
	return *this;
}

Report::Report(Report& other)
{
	FI_ID = other.FI_ID;
	ThirdParty_ID = other.ThirdParty_ID;
	duediligenceDate = other.duediligenceDate;
	reportDate = other.reportDate;
	duediligenceType = other.duediligenceType;

}

void Report::printReport(ostream& os)
{

	os << "Financial Institution ID: " << FI_ID << std::endl;
	os << "Third party ID " << ThirdParty_ID << std::endl;
	os << "Date due diligence was made: " << duediligenceDate << std::endl;
	os << "Date report was made: " << reportDate << std::endl;
	os << "Type of due diligence: " << duediligenceType << std::endl;

}
