#include "PasswordManager.h"
#include "picosha2.h"
#include <random>
#include <ctime>
#include <iostream>

PasswordManager::PasswordManager()
{
	readFile();
}

PasswordManager::~PasswordManager()
{
	writeFile();
}

bool PasswordManager::firstTimeLogin(std::string user, std::string pass)
{
	addUser(user, pass);
	return login(user, pass);
}

bool PasswordManager::login(std::string user, std::string pass)
{
	auto givenUser = allUserData.find(user);
	if (givenUser != allUserData.end())
	{
		std::string userSalt = givenUser->second.salt;
		std::string givenPass = encryptPassword(pass, userSalt);

		if (givenPass == givenUser->second.encryptedPassword) return true;
	}
	return false;
}

void PasswordManager::addUser(std::string user, std::string pass)
{
	std::string salt = randomSalt();
	std::string encpass = encryptPassword(pass, salt);
	
	addUser(user, salt, encpass);
}

void PasswordManager::addUser(std::string user, std::string salt, std::string encryptedPassword)
{
	PassInfo info(salt, encryptedPassword);
	allUserData.insert(std::pair<std::string, PassInfo>(user, info));
}

void PasswordManager::removeUser(std::string user)
{
	auto givenUser = allUserData.find(user);
	if (givenUser != allUserData.end())
	{
		allUserData.erase(givenUser);
	}
}

void PasswordManager::printAllUsers()
{
	for (auto it = allUserData.begin(); it != allUserData.end(); it++)
	{
		std::cout << it->first << " " << it->second << "\n";
	}
}



void PasswordManager::readFile()
{
	std::ifstream file(FILENAME);

	std::string user;
	std::string salt;
	std::string encpass;

	while (file >> user >> salt >> encpass)
	{

		std::cout << user << ' ' << salt << ' ' << encpass << std::endl;
		addUser(user, salt, encpass);
	}

	file.close();
}

void PasswordManager::writeFile()
{
	std::ofstream file(FILENAME);

	for (auto it = allUserData.begin(); it != allUserData.end(); it++)
	{
		file << it->first << " " << it->second << "\n";
	}

	file.close();
}

std::string PasswordManager::encryptPassword(std::string password, std::string salt)
{
	std::string result;
	std::string input(password);
	input += salt;

	std::vector<unsigned char> hash(picosha2::k_digest_size);
	picosha2::hash256_hex_string(input, result);

	return result;
}

std::string PasswordManager::randomSalt()
{
	srand(time(nullptr));
	std::string salt;
	char ch;

	for (int i = 0; i < 8; i++)
	{
		ch = static_cast<char>(rand() % 255);
		salt += ch;
	}

	return salt;
}

std::ostream & operator<<(std::ostream & os, PassInfo & info)
{
	os << info.salt << ' ' << info.encryptedPassword;
	return os;
}

void PasswordManager::generateEncryptionKey(std::string encryptedPass)
{
	long int firstPrime, secondPrime;
	firstPrime = 12809;
	secondPrime = 18371;
  	for(i = 0; encryptedPass[i] != NULL; i++)
    		encryptedPass[i] = encryptedPass[i];
	keyModulus = firstPrime * secondPrime;
	totientFunction = (firstPrime - 1) * (secondPrime - 1);
	
	long int key;
	key = 0;
	for(i = 2; i < totientFunction; i++)
	{
		if(totientFunction % i == 0)
		 continue;
		flag = prime(i);
		if(flag == 1 && i != firstPrime && i != secondPrime)
		{
			 publicKey[key] = i;
			 flag = cd(publicKey[key]);
			 if(flag > 0)
			 {
			    publicKeyInverse[key] = flag;
			    key++;
			 } //endif
			 if(key == 99)
			 break;
		}//endif
	} //endfor
	long int pt, ct, actualKey, len;
	key = publicKey[0];
	i = 0;
	len = encryptedPass.length();

	while(i != len)
	{
		pt = static_cast<long int>(decrypted[i]);
		pt = pt - 96;
		actualKey = 1;
		for(maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
		{
			 actualKey = actualKey * pt;
			 actualKey = actualKey % keyModulus;
		}//endfor
		temp[i] = actualKey;
		ct= actualKey + 96;
		encrypted[i] = static_cast<char>(ct);
		i++; 																						//64
	}//endwhile
	encrypted[i] = -1;
	pt = 0, ct = 0, key = publicKeyInverse[0], actualKey = 0;
   i = 0;
   while(encrypted[i] != -1)
   {
      ct = temp[i];
      actualKey = 1;
      for(maxValOfKey = 0; maxValOfKey < key; maxValOfKey++)
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
long int PasswordManager::cd(long int a)
{
	long int key = 1;
	while(1)
	{
		key = key + totientFunction;
		if(key % a == 0)
		 return(key/a);
	}	
}
long int PasswordManager::prime(long int pr)
{
   long int i;
   maxValOfKey = sqrt(pr);
   for(i = 2; i <= maxValOfKey; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }
