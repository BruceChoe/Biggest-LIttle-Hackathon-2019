#pragma once
#include "Block.h"
#include "Blockchain.h"
#include "sha256.h"
#include <time.h>
#define nDifficulty 4

template <class DataType>
Block<DataType>::Block(uint32_t nIndexIn, DataType& inputData)
	: _nIndex(nIndexIn), data(inputData)
{
	_nNonce = -1;
	_tTime = time(nullptr);
}

template <class DataType>
string Block<DataType>::GetHash() {
	return _sHash;
}

template <class Datatype>
void Block<DataType>::MineBlock() {
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

template <class DataType>
inline string Block<DataType>::_CalculateHash() const {
	std::stringstream ss;
	ss << _nIndex << _tTime << _nNonce << sPrevHash <<;
	return sha256(ss.str());
}

template <class DataType>
uint32_t Block<DataType>::getIndex() {
	return _nIndex;
}

template <class DataType>
DataType& Block<DataType>::getReport() {
	return reportDocs;
}
