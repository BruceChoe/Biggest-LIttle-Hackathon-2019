#define nDifficulty 4

template <class DataType>
Block<DataType>::Block(uint32_t nIndexIn, DataType& inputData)
	: _nIndex(nIndexIn), data(inputData)
{
	_nNonce = -1; //Sets nonce to -1
	_tTime = time(nullptr); //Sets the time for later random values
}

template <class DataType>
string Block<DataType>::GetHash() {
	return _sHash; //Returns the hash
}

template <class DataType>
void Block<DataType>::MineBlock() {
	char cstr[nDifficulty + 1]; //Difficulty plus 1 indicates how many zeros we are looking for within the hash
	for (uint32_t i = 0; i < nDifficulty; ++i) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr); //Creates a string from cstr
	do {
		_nNonce++; //adds to the nonce
		_sHash = _CalculateHash(); //Calculates the Hash from the given function
	} while (_sHash.substr(0, nDifficulty) != str); //Is true while we can't find the given hash

	cout << "Block mined: " << _sHash << endl;
}

template <class DataType>
inline string Block<DataType>::_CalculateHash() const {
	std::stringstream ss; 
	ss << _nIndex << _tTime << _nNonce << sPrevHash;
	return sha256(ss.str()); //Hashes the newly made string stream using all of the new values
}

template <class DataType>
uint32_t Block<DataType>::getIndex() {
	return _nIndex; //returns index of data
}

template <class DataType>
DataType& Block<DataType>::getData() {
	return data; //returns data of a given block
}
