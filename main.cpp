/*
*   CS302 Bonus Project Submission. 
*   Authors: Bruce Choe, Daniel Enriquez, Erik Marsh. 
*   View the Readme for project specs
*   View log.pdf for project output
*   Executable name after compiling: hashing
*/

#include <iostream>
#include <fstream>
#include "BlockChain.h"
#include "Keys.h"
#include <limits>
const char * FILENAME = "blocks.txt";

template <typename DataType> void printBlocks(Blockchain<DataType> & blockchain, ostream &os);
template <typename DataType> void writeFile(Blockchain<DataType> & blockchain);
bool isPrime(int number);
int generatePrime();

int main()
{
    Blockchain<int> blockchain;
    std::vector<Block<int>> blocks;
	int decryptedPrivateKey, decryptedPublicKey;
	int encryptedPrivateKey, encryptedPublicKey;
	srand(time(NULL)); //Sets the random seed to be equal to the time

    // Generate public and private keys, both encypted and decrypted. 
    cout << endl << "For demonstration purposes, we'll generate random public and private keys for you. ";    
	generateKeys(generatePrime(), generatePrime(), encryptedPrivateKey, decryptedPrivateKey);
	generateKeys(generatePrime(), generatePrime(), encryptedPublicKey, decryptedPublicKey);

    int option;    
    int i = 1; //i is an iterator for the position in the block chain
    int value = 0;
    int key = 0;
    do {
        cout << "\n";
        cout << "Your keys:\n";
        cout << "Public Key: " << decryptedPublicKey << "\n";
        cout << "Private Key: " << decryptedPrivateKey << "\n";
        cout << "(1) Add a block to the Block Chain\n(2) View the Block Chain\n(3) Check if Block Chain has been manipulated\n(4) Write the existing Block Chain to the file\n(5) Exit\n";
        cout << "Enter in your option: ";
        cin >> option;
        // Sanitize input
        if(!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "\n";
        
        switch (option)
        {
            case 1: // Add block to chain using private key
                cout << "Enter in your private key: ";
                cin >> key;
                if(!cin) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                if (key == decryptedPublicKey) 
                {
                    cout << "Error: Unable to sign block using public key. Please use your private key.\n";
                }
                else if (key == decryptedPrivateKey)
                {
                    cout << "Permission granted\n";
                    cout << "Add an integer value to the Block Chain: ";
                    cin >> value;
                    if(!cin)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Invalid data entry." << endl;
                        break;
                    }
                    // Add block to chain
                    cout << "Adding value " << value << " to the Block Chain at location " << i <<"\n";
                    Block<int> temp(i, value);
                    blockchain.AddBlock(temp);
                    blocks.push_back(temp);
                    i++;
                }
                else
                {
                    cout << "Invalid Key\n";
                }
                break; //case 1

            case 2: //prints out all of the blocks
                printBlocks(blockchain, std::cout);
                break; //case 2

            case 3: //Checks if chain is valid or not
                if (blockchain.checkValid())
                    cout << "Block Chain is valid\n";
                else
                    cout << "Block Chain is invalid\n";
                break; //case 3

            case 4: //Prints the block chain to an existing file
                 cout << "All of the blocks are now written into the file blocks.txt\n";
                 writeFile(blockchain);
                break; //case 4

            case 5: //exit case
                cout << "Bye!\n";
                return 1;
                break; //case 5

            default:
                cout <<"Error, invalid input\n";
        }
    } while (option != 0);

    return 0;
}

// Print blockchain hash map to terminal. Note: blockchain is printed in order of lowest to greatest hash signature, NOT chronologically. 
template <typename DataType>
void printBlocks(Blockchain<DataType> & blockchain, ostream &os)
{
    blockchain.myMap.printMap(os);
}

// Write blockchain to file
template <typename DataType>
void writeFile(Blockchain<DataType> & blockchain)
{
    std::ofstream file(FILENAME);
    blockchain.myMap.printMap(file);
    file.close();
}

// Lowest overhead cost of generating a random prime
int generatePrime()
{
	int num = rand() % 10000;
	while (1) //Brute force generation method
	{
	num++;
	if (isPrime(num))
		return num;
	}
}

// Simple primality test
bool isPrime(int number)
{
	for (int i = 2; i <= number/2; i++)
	{
		if (number%i == 0)
			return false;
	}
	return true;
}
