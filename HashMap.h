#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include "Block.h"

template <class DataType>
class HashMap {
private:
	std::map<std::string, DataType> m; //m is the map
	string tail; 
	
public:
	void Insert(string hash, DataType data)
	{
		m.emplace(hash, data);
		tail = hash;

	}
	
	string getLastHash()
	{
		return tail;
	}
	
	
	
	void printMap(ostream& os)
	{
		std::map<std::string, DataType>::iterator it = m.begin();
		while (it != m.end()) {
			os << "Hash: " << it->first.string << " ";
			os << "With Data: " <<it->second.DataType << " ";
			it++;
		}
		os << "\n";
	}
};
