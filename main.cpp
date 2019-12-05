#include <iostream>
#include <fstream>
#include "BlockChain.h"
#include "Keys.h"
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

    cout << endl << "For demonstration purposes, we'll generate random public and private keys for you. ";    
	generateKeys(generatePrime(), generatePrime(), encryptedPrivateKey, decryptedPrivateKey);
	generateKeys(generatePrime(), generatePrime(), encryptedPublicKey, decryptedPublicKey);
	//cout << "Decrypted Private Key: " << decryptedPrivateKey << "\nEncrypted Private Key: " << encryptedPrivateKey << endl;
	//cout << "Decrypted Public Key: " << decryptedPublicKey << "\nEncrypted Public Key: " << encryptedPublicKey << endl;

    int key; //This is the user input
    //cout << "Use your encrypted keys to interface with the blockchain." << endl;

    int option;    
    int i = 1; //i is an iterator for the position in the block chain
    do {
        cout << "\n";
        cout << "Your keys:\n";
        cout << "Public Key: " << decryptedPublicKey << "\n";
        cout << "Private Key: " << decryptedPrivateKey << "\n";
        cout << "(1) Add a block to the Block Chain\n(2) View the Block Chain\n(3) Check if Block Chain has been manipulated\n(4) Write the existing Block Chain to the file\n(5) Exit\n";
        cout << "Enter in your option: ";
        cin >> option;
        int value;
        cout << "\n";
        
        switch (option)
        {
            case 1: //Add to the block chain
                cout << "Enter in your private key: ";
                cin >> key;
                if (key == decryptedPublicKey)
                    cout << "Error: Unable to sign block using public key. Please use your private key.\n";
                else if (key == decryptedPrivateKey)
                {
                    cout << "Permission granted\n";
                    cout << "Add an integer value to the Block Chain: ";
                    cin >> value;
                    if (value <= 2147483647 || value >= -2147483648)
                    {
                        cout << "Adding value " << value << " to the Block Chain at location " << i <<"\n";
                        Block<int> temp(i, value);
                        blockchain.AddBlock(temp);
                        blocks.push_back(temp);
                        i++;
                    }
                    else
                        cout << "Value exceeds allowable integer limits.\n";
                }
                else
                    cout << "Invalid Key\n";
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

template <typename DataType>
void printBlocks(Blockchain<DataType> & blockchain, ostream &os)
{
    blockchain.myMap.printMap(os);
}

template <typename DataType>
void writeFile(Blockchain<DataType> & blockchain)
{
    std::ofstream file(FILENAME);
    blockchain.myMap.printMap(file);
    file.close();
}

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
bool isPrime(int number)
{
	for (int i = 2; i <= number/2; i++)
	{
		if (number%i == 0)
			return false;
	}
	return true;
}
