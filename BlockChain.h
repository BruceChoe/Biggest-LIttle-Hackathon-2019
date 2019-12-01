#ifndef BLOCK_CHAIN
#define BLOCK_CHAIN

#include <cstdint>
#include <vector>
#include "Block.h"
#include "HashMap.h"

using namespace std;

template <typename DataType>
class Blockchain {
public:
	Blockchain();
    	Block<DataType> _GetLastBlock() const;
	void AddBlock(Block<DataType> & bNew);
	HashMap<DataType> myMap;
private:
	uint32_t _nDifficulty;
	vector<Block<DataType>> _vChain;
};

#include "BlockChain.cpp"

#endif
