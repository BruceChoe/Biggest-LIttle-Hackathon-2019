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
   
    cout << "Here are 2 prime numbers, meant to show the concept of private and public keys\n";
    cout << "Public Key: " << publicKey << "\n";
    cout << "Private Key: " << privateKey << "\n";    
    cout << "When asked to, input either key in order to have access to certain permissions of the given key\n";
    
	int decryptedPrivateKey;
	int encryptedPrivateKey;
	int decryptedPublicKey;
	int encryptedPublicKey;
	srand(time(NULL)); //Sets the random seed to be equal to the time
	cout << "Generating Keys\n";
	generateKeys(generatePrime(), generatePrime(), encryptedPrivateKey, decryptedPrivateKey);
	generateKeys(generatePrime(), generatePrime(), encryptedPublicKey, decryptedPublicKey);
	cout << "Decrypted Private Key: " << decryptedPrivateKey << "\nEncrypted Private Key: " << encryptedPrivateKey << endl;
	cout << "Decrypted Public Key: " << decryptedPublicKey << "\nEncrypted Public Key: " << encryptedPublicKey << endl;
    
    
    int option;    
    int i = 1; //i is an iterator for the position in the block chain
    do {
        cout << "\n\n";
        cout << "Your keys:\n";
        cout << "Public Key: " << publicKey << "\n";
        cout << "Private Key:" << privateKey << "\n";
        cout << "(1) Add something to the Block Chain\n(2) Look at the Block Chain\n(3) Check if Block Chain has been manipulated\n(4) Write the existing Block Chain to the file\n(5) To exit\n";
        cout << "Enter in your option: ";
        cin >> option;
        int key; //This is the key the user enters
        int value;
        cout << "\n\n";
        
        switch (option)
        {
            case 1: //Add to the block chain
                cout << "Enter in key: ";
                cin >> key;
                if (key == publicKey)
                    cout << "Error: Can not enter data into Block Chain using public key\n";
                else if (key == privateKey)
                {
                    cout << "Permission granted\n";
                    cout << "Add an integer value to the Block Chain: ";
                    cin >> value;
                    cout << "Adding value " << value << " to the Block Chain to location " << i <<"\n";
                    Block<int> temp(i, value);
                    blockchain.AddBlock(temp);
                    blocks.push_back(temp);
                    i++;
                }
                else
                    cout << "Key not detected\n";
                break; //case 1



            case 2: //prints out all of the blocks
                cout << "Enter in key: ";
                cin >> key;
                if (key == publicKey || key == privateKey)
                   printBlocks(blockchain, std::cout);
                else
                    cout << "Key not detected\n";
                break; //case 2



            case 3: //Checks if chain is valid or not
                if (blockchain.checkValid())
                    cout << "Block Chain is valid\n";
                else
                    cout << "Block Chain is invalid\n";
                break; //case 3




            case 4: //Prints the block chain to an existing file
                cout << "Enter in key: ";
                cin >> key;
                if (key == publicKey)
                    cout << "Error: Can not enter data into block chain using public key\n";
                else if (key == privateKey)
                {
                    cout << "All of the blocks are now written into the file blocks.txt\n";
                    writeFile(blockchain);
                }
                else
                    cout << "Key not detected\n";
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
/*
    for (Block<DataType> b : vec)
    {
        std::cout << "Block " << b.getIndex() << " contains " << b.getData() << std::endl;
        std::cout << "    Hash: " << b.GetHash() << std::endl;
    }
*/
}

template <typename DataType>
void writeFile(Blockchain<DataType> & blockchain)
{
    std::ofstream file(FILENAME);
    blockchain.myMap.printMap(file);
/*
    for (Block<DataType> b : vec)
        file << b.getIndex() << " " << b.getData() << " " << b.GetHash() << "\n";
*/
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
