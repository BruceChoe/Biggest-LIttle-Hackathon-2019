#ifndef BLOCK_CHAIN
#define BLOCK_CHAIN
#include <cstdint>
#include <vector>
#include "Block.h"
#include "HashMap.cpp"
using namespace std;
class Blockchain {
public:
	Blockchain();
    Block _GetLastBlock() const;
	void AddBlock(Block bNew);
	HashMap myMap;
private:
	uint32_t _nDifficulty;
	vector<Block> _vChain;

};
#endif
