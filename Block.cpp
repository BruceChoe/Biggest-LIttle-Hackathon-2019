#pragma once
#include "Block.h"
#include "Blockchain.h"
#include "sha256.h"
#include <time.h>
#include "FI.h"
#include "ThirdParty.h"
#include "Report.h"
#define nDifficulty 4

Block::Block(uint32_t nIndexIn, const string& sDataIn, Report& rReportDocsIn)
	: _nIndex(nIndexIn), _sData(sDataIn), reportDocs(rReportDocsIn)
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
	ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

	return sha256(ss.str());
}
