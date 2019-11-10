//Block.H
//Block.H
#ifndef BLOCK
#define BLOCK
#include <iostream>
#include <cstdint>
#include <sstream>
#include "Report.h"
#include "FI.h"
#include "ThirdParty.h"

using namespace std;
/*
	Creation of a block: enter private key, info, create.
*/
class Block {
public:
	string sPrevHash;
	Block(uint32_t nIndexIn, FI& fiID, ThirdParty& tpID, Report& rReportDocsIn);
	string GetHash();
	void MineBlock();

private:
	uint32_t _nIndex;
	int64_t _nNonce;
	string _sHash;
	time_t _tTime;
	FI& fiID;
	ThirdParty& tpID;
	Report& reportDocs;

	string _CalculateHash() const;
};
#endif
