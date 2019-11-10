#pragma once
#include "Blockchain.h"

Blockchain::Blockchain() {
	Report emptyReport();
	
	_vChain.emplace_back(Block(0, "Genesis Block", emptyReport));
	_nDifficulty = 6;
}

void Blockchain::AddBlock(Block bNew) {
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock();
	_vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
	return _vChain.back();
}
