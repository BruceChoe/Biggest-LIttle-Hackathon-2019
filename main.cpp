#include <iostream>
#include <fstream>
#include "BlockChain.h"

const char * FILENAME = "blocks.txt";

template <typename DataType> void printBlocks(std::vector<Block<DataType>> & vec);
template <typename DataType> void writeFile(std::vector<Block<DataType>> & vec);

int main()
{
    Blockchain<int> blockchain;
    std::vector<Block<int>> blocks;
    int data = 16;

    for (int i = 1; i <= 3; i++)
    {
        data = data * i;
        Block<int> temp(i, data);
        blockchain.AddBlock(temp);
        blocks.push_back(temp);
    }

    printBlocks(blocks);
    writeFile(blocks);

    return 0;
}

template <typename DataType>
void printBlocks(std::vector<Block<DataType>> & vec)
{
    for (Block<DataType> b : vec)
    {
        std::cout << "Block " << b.getIndex() << " contains " << b.getData() << std::endl;
        std::cout << "    Hash: " << b.GetHash() << std::endl;
    }
}

template <typename DataType>
void writeFile(std::vector<Block<DataType>> & vec)
{
    std::ofstream file(FILENAME);

    for (Block<DataType> b : vec)
        file << b.getIndex() << " " << b.getData() << " " << b.GetHash() << "\n";
    
    file.close();
}