#include <iostream>
#include "BlockChain.h"

template <typename DataType> void printBlock(Block<DataType> & b);

int main()
{
    //create blockchain
    //add some blocks
    //print them out

    Blockchain<int> blockchain;

    int a = 16;
    int b = 32;
    int c = 64;

    Block<int> b1(1, a);
    Block<int> b2(2, b);
    Block<int> b3(3, c);

    printBlock(b1);
    printBlock(b2);
    printBlock(b3);

    blockchain.AddBlock(b1);
    blockchain.AddBlock(b2);
    blockchain.AddBlock(b3);

    return 0;
}

template <typename DataType>
void printBlock(Block<DataType> & b)
{
    std::cout << "Block " << b.getIndex() << " contains " << b.getData() << std::endl;
    std::cout << "    Hash: " << b.GetHash() << std::endl;
}