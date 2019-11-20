#pragma once
#include "Block.h"
#include "Blockchain.h"
#include "sha256.h"
#include <time.h>
#include "FI.h"
#include "ThirdParty.h"
#include "Report.h"
#define nDifficulty 4

/*
Block::Block()
{
	_nIndex = -1;
	ThirdParty dtpID;
	FI deffID;
	Report defDocs;
	fiID = deffID;
	tpID = dtpID;
	reportDocs = defDocs;
}
*/

/*
Block::Block(uint32_t nIndexIn, Report& rReportDocsIn)
	: _nIndex(nIndexIn), fiID(rReportDocsIn.FI_ID), tpID(rReportDocsIn.ThirdParty_ID), reportDocs(rReportDocsIn)
{

}
*/

Block::Block(uint32_t nIndexIn, FI& fiIDIn, ThirdParty& tpIDIn, Report& rReportDocsIn)
	: _nIndex(nIndexIn), fiID(fiIDIn), tpID(tpIDIn), reportDocs(rReportDocsIn)
{
	_nNonce = -1;
	_tTime = time(nullptr);
}

string Block::GetHash() {
	return _sHash;
}

void Block::MineBlock() {
	char cstr[nDifficulty + 1];
	for (uint32_t i = 0; i < nDifficulty; ++i) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr);
	do {
		_nNonce++;
		_sHash = _CalculateHash();
	} while (_sHash.substr(0, nDifficulty) != str);

	cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
	std::stringstream ss;
	ss << _nIndex << _tTime << _nNonce << sPrevHash << fiID.getID() << tpID.getID();
	return sha256(ss.str());
}

uint32_t Block::getIndex() {
	return _nIndex;
}

Report& Block::getReport() {
	return reportDocs;
}