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
	void Insert(string hash, Report report)
	{
		m.emplace(hash, report);
		tail = hash;

	}

	void printMap(ostream& os)
	{
		std::map<std::string, DataType>::iterator it = m.begin();
		while (it != m.end()) {
			os << it->second.DataType << " ";
			it++;
		}
		os << "\n";
	}
};
