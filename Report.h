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

	int getFiID();
	int getTpID();
	//string getThirdPartyName(); Maybe later? 
    string getDDD()
    {
        return duediligenceDate;
    }
    string getDDT()
    {
        return duediligenceType;
    }
    string getDate()
    {
        return reportDate;
    }
};
#endif //REPORT_H


