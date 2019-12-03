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
	string tail; //the last hash (useful for checking if valid)
	
public:
	void Insert(string hash, DataType data)
	{
		m.emplace(hash, data); //Emplaces new data into the map
		tail = hash; //makes the tail equal to a hash, each insertion it is now making the tail equal to the newest hash

	}
	
	string getLastHash()
	{
		return tail; //gets the last hash, in this case just the tail is all we need
	}
	
	
	
	void printMap(ostream& os)
	{
		os << "\nPrinting out map according to lowest to greatest hash signature\n";
		//std::map<std::string, DataType>::iterator it = m.begin(); --> This is what the auto should create
		auto it = m.begin(); //iterator starting at the start of the map
		while (it != m.end()) {
			os << "Hash: " << it->first << " ";
			os << "With Data: " <<it->second << " ";
			it++;
			os << "\n";
		}
		os << "\n";
	}
};
