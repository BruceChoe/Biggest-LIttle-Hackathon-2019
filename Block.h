//Block.H
//Block.H
#ifndef BLOCK
#define BLOCK
#include <iostream>
#include <cstdint>
#include <sstream>
#include "Report.h"


using namespace std;

class Block {
public:
	string sPrevHash;
	Block(uint32_t nIndexIn, const string& sDataIn, Report& rReportDocsIn);

	string GetHash();

	void MineBlock(); //all traces of _ndifficulty deleted and hardocded at length 4 instead, VLA problems

private:
	uint32_t _nIndex;
	int64_t _nNonce;
	string _sData;
	string _sHash;
	time_t _tTime;

	Report& reportDocs;

	string _CalculateHash() const;
};
#endif
