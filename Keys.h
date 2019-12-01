#pragma once

#include <map>
#include <iostream>
#include <utility>
#include <random>
#include <ctime>

template <class DataType>
class Keys
{
public:
	void generateEncryptionKey(std::string encryptedPass); //Two different keys will be made using this hashing method
	long int publicKey[50];

private:
	
	long int keyModulus, totientFunction, i, flag; // i is just any iterator
	long int publicKeyInverse[50], temp[50], maxValOfKey;
	char encrypted[50], decrypted[50]; // encrypted = private key
	long int cd(long int a);
	long int prime(long int pr);

};

#include "Keys.cpp"
