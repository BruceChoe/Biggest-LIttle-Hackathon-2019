//Already included within the header file
template <typename DataType>
Blockchain<DataType>::Blockchain() {
	DataType data;

	_vChain.emplace_back(Block<DataType>(0, data)); //Adds vChain to the back of the block chain
	_nDifficulty = 6; //With difficulty of 6
}

template <typename DataType>
void Blockchain<DataType>::AddBlock(Block<DataType> & bNew) { //Add a new block to the chain
	bNew.sPrevHash = _GetLastBlock().GetHash(); //Gets the previous hash to allow it to point to it
	bNew.MineBlock(); //Mines the block
	_vChain.push_back(bNew); //pushes it back onto the chain
	myMap.Insert(bNew.GetHash(), bNew.getData()); //Inserts it into the map
}

template <typename DataType>
Block<DataType> Blockchain<DataType>::_GetLastBlock() const {
	return _vChain.back(); //returns the last block in the chain
}

template <typename DataType>
bool Blockchain<DataType>::checkValid()
{	
	return _GetLastBlock().GetHash() == myMap.getLastHash(); //Returns if the last hash is equal to the one in the map, if valid it returns true, if invalid it returns false, it should always return true (unless manipulated)
}
