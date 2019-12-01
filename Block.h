//Block.H
//Block.H
#ifndef BLOCK
#define BLOCK
#include <iostream>
#include <cstdint>
#include <sstream>


using namespace std;
/*
	Creation of a block: enter private key, info, create.
*/
template <class DataType>
class Block {
public:
	string sPrevHash;
	
	Block(uint32_t nIndexIn, DataType& inputData);
	string GetHash();
	void MineBlock();
	uint32_t getIndex();
	DataType& getData();
private:
	uint32_t _nIndex;
	int64_t _nNonce;
	string _sHash;
	time_t _tTime;
	DataType& data;

	string _CalculateHash() const;
};
#endif
