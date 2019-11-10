#include "Report.h"
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
	: FI_ID(fi_id), ThirdParty_ID(thirdparty_id), duediligenceDate(duediligencedate), reportDate(reportdate), duediligenceType(duediligencetype)
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