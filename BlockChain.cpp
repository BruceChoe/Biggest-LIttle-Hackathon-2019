template <typename DataType>
Blockchain<DataType>::Blockchain() {
	DataType data;

	_vChain.emplace_back(Block<DataType>(0, data));
	_nDifficulty = 6;
}

template <typename DataType>
void Blockchain<DataType>::AddBlock(Block<DataType> bNew) {
	bNew.sPrevHash = _GetLastBlock().GetHash();
	bNew.MineBlock();
	_vChain.push_back(bNew);
	myMap.Insert(bNew.GetHash(), bNew.getData());
}

template <typename DataType>
Block<DataType> Blockchain<DataType>::_GetLastBlock() const {
	return _vChain.back();
}
