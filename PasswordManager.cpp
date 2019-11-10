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
