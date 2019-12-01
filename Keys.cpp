template <class DataType>
void Keys<DataType>::generateEncryptionKey(std::string hash)
{
	long int firstPrime, secondPrime;
	firstPrime = 12809;
	secondPrime = 18371;
	for (i = 0; hash[i] != NULL; i++)
		hash[i] = hash[i];
	keyModulus = firstPrime * secondPrime;
	totientFunction = (firstPrime - 1) * (secondPrime - 1);

	long int key;
	key = 0;
	for (i = 2; i < totientFunction; i++)
	{
		if (totientFunction % i == 0)
			continue;
		flag = prime(i);
		if (flag == 1 && i != firstPrime && i != secondPrime)
		{
			publicKey[key] = i;
			flag = cd(publicKey[key]);
			if (flag > 0)
			{
				publicKeyInverse[key] = flag;
				key++;
			} //endif
			if (key == 99)
				break;
		}//endif
	} //endfor
	long int pt, ct, actualKey, len;
	key = publicKey[0];
	i = 0;
	len = hash.length();

	while (i != len)
	{
		pt = static_cast<long int>(decrypted[i]);
		pt = pt - 96;
		actualKey = 1;
		for (maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
		{
			actualKey = actualKey * pt;
			actualKey = actualKey % keyModulus;
		}//endfor
		temp[i] = actualKey;
		ct = actualKey + 96;
		encrypted[i] = static_cast<char>(ct);
		i++; 																						//64
	}//endwhile
	encrypted[i] = -1;
	pt = 0, ct = 0, key = publicKeyInverse[0], actualKey = 0;
	i = 0;
	while (encrypted[i] != -1)
	{
		ct = temp[i];
		actualKey = 1;
		for (maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
		{
			actualKey = actualKey * ct;
			actualKey = actualKey % keyModulus;
		}//endfor
		pt = actualKey + 96;
		decrypted[i] = static_cast<char>(pt);
		i++;
	}//endwhile
	decrypted[i] = -1;

}//end generateEncryptionKey


template <class DataType>
long int Keys<DataType>::cd(long int a)
{
	long int key = 1;
	while (1)
	{
		key = key + totientFunction;
		if (key % a == 0)
			return(key / a);
	}
}

template <class DataType>
long int Keys<DataType>::prime(long int pr)
{
	long int i;
	maxValOfKey = sqrt(pr);
	for (i = 2; i <= maxValOfKey; i++)
	{
		if (pr % i == 0)
			return 0;
	}
	return 1;
}
