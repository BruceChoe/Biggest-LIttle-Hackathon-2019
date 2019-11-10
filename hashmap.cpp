#include <iostream>
#include <map>
#include <unordered_map>
//https://thispointer.com/how-to-search-by-value-in-a-map-c/

class HashMap{
	private: 
	std::map<std::string,Report> m;
	string *head;
	int size;
	public:
	void Insert(string hash, Report report)
	{
		m.insert(hash, report);
		head = *hash;
		size++;
	}
	Report* Search(string hash)
	{
		auto location = m.find(hash);
		
		//Report *r = location.second;
		
		auto temp = m.at[location];
		return temp->second;
	}
	Report* SearchByValue(Report report)
	{
		auto it = m.begin();
		// Iterate through the map
		while(it != m.end())
		{
			// Check if value of this entry matches with given value
			if(it->second == report)
			{
				return &(it->second);
			}
			// Go to next entry in map
			it++;
		}
	}
	
};
