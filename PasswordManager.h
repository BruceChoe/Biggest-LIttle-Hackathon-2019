#pragma once

#include <map>
#include <iostream>
#include <utility>

const char FILENAME[13] = "userdata.bin";

struct PassInfo
{
	PassInfo(std::string& p_salt, std::string& p_encryptedPassword)
		: salt(p_salt), encryptedPassword(p_encryptedPassword)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, PassInfo& info);

	std::string salt;
	std::string encryptedPassword;
};

class PasswordManager
{
public:
	PasswordManager();
	~PasswordManager();

	bool firstTimeLogin(std::string user, std::string pass);
	bool login(std::string user, std::string pass);

	void addUser(std::string user, std::string pass);
	void addUser(std::string user, std::string salt, std::string encryptedPassword);
	void removeUser(std::string user);
	std::string encryptPassword(std::string password, std::string salt);
	void generateEncryptionKey(std::string encryptedPass); //Two different keys will be made using this hashing method
	void printAllUsers();

	std::string randomSalt(); 
	long int publicKey[50];

private:
	std::map<std::string, PassInfo> allUserData;

	//PassInfo encrypt(std::string user, std::string pass);

	void writeFile();
	void readFile();

	long int keyModulus, totientFunction, i, flag;
	long int publicKeyInverse[50], temp[50], maxValOfKey;
	char encrypted[50], decrypted[50]; // encrypted = private key
	long int cd(long int a);
	long int prime(long int pr);

};