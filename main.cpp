#pragma once
#include "Blockchain.h"
#include "PasswordManager.h"
#include <iostream>

using std::cout;
using std::cin;
int main() {
	Blockchain bChain = Blockchain();
	FI id1;
	FI id2("Employers", 54);
	FI id3("Bombora", 113);

	ThirdParty tp1;
	ThirdParty tp2(5, "CompanyRiskX", "Financial");
	ThirdParty tp3;

	Report rep1;
	Report rep2(1, 2, "hi", "10/31", "Audit");
	Report rep3;

	cout << "Mining block 1..." << endl;
	bChain.AddBlock(Block(1, id1, tp1, rep1));

	cout << "Mining block 2..." << endl;
	bChain.AddBlock(Block(2, id2, tp2, rep2));

	cout << "Mining block 3..." << endl;
	bChain.AddBlock(Block(3, id3, tp3, rep3));
	rep1.printReport(std::cout);
	rep2.printReport(std::cout);
	cout << endl;

	int cont = 1;
	int choice = 0;
	int index = 0;
	long int* keyPtr = nullptr;
	long int key = 0;
	string fiUser;
	string fiPass;
	PasswordManager user;
	std::stringstream ss;
	//Blockchain bChain = Blockchain();
	do
	{
		cout << "Welcome to the BlockChain" << endl;
		cout << "Options: " << endl << "1) New User" << endl << "2) Add to Chain" << endl << "3) Exit" << endl << "Select choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				// add to chain
				// If new user
				cout << "Enter your financial institution's name: ";
				cin >> fiUser;
				cout << "Enter a password for your institution: ";
				cin >> fiPass;
				user.firstTimeLogin(fiUser, fiPass);
				user.generateEncryptionKey(user.encryptPassword(fiPass, user.randomSalt()));
				break;
			case 2:
				// If not new user
				cout << "Enter your username: ";
				cin >> fiUser;
				cout << "Enter your password: ";
				cin >> fiPass;
				user.login(fiUser, fiPass);
				cout << user.publicKey << endl;
				/*
				//cout << user.publicKey[6];
				//cout << key << endl;
				//key = *user.publicKey;
				//user.printAllUsers();
				
				for (unsigned i = 0; i < sizeof user.publicKey / sizeof user.publicKey[0]; ++i)
					ss << user.publicKey[i];
				ss >> key;
				cout << key; //603215
				*/
				//bChain.AddBlock(Block(index++, key, tp1, rep1));
				break;
			case 3:
				cont = 0;
				break;
			default:
				break;
		}
	}
	while(cont == 1);
	return 0;
}
