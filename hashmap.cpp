#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include "Block.h"

class HashMap{
	private: 
	std::map<std::string,Report> m;
	std::map<std::string,Report> m1;
	std::map<std::string,Report> m2;
	std::map<std::string,Report> m2;
	std::map<std::string,Report> m3;
	std::map<std::string,Report> m4;
	//string *head;
	
	public:
	void Insert(string hash, Report report)
	{
		m.emplace(hash, report);
		m1.emplace(hash, report);
		m2.emplace(hash, report);
		m3.emplace(hash, report);
		m4.emplace(hash, report);
	//	head = *hash;
	
	}
	void checkHashes();
	{
		if (m.end() != m1.end() ||m.end() != m2.end() ||m.end() != m3.end() ||m.end() != m4.end())
		{
			cout << "FATAL ERROR: HASH NOT MATCHING\n\n\n\n";
			exit;
		}
	}
	/*
	Report* Search(string hash)
	{
		auto location = m.find(hash);
		
		//Report *r = location.second;
		
		auto temp = m.at[location];
		return temp->second;
	}
	*/
	Report* SearchByID(int FI_ID)
	{
		auto it = m.begin();
		// Iterate through the map
		while(it != m.end())
		{
			// Check if value of this entry matches with given value
			if((it->second.getFiID())==FI_ID)
			{
				return &(it->second);
			}
			// Go to next entry in map
			it++;
		}
	}
	
};
