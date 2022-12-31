#ifndef hashTable__cpp
#define hashTable__cpp
#include <bits/stdc++.h>
using namespace std;

template<class T> struct myHash 
{
	static size_t hashFunction(const string& s) 
	{
    	int sum = 0;
    	for (int i = 0; i < s.size(); ++i) 
		{
			sum += s[i];
		}
		return sum % 23;
  	}
	static size_t hashFunction(const int& m) 
	{
    	return hash<int>()(m);
  	}
  	static size_t hashFunction(const double& b) 
	{
    	return hash<double>()(b);
  	}
};

template<class Key, class Val, class Hash = myHash <Key>>
class HashTable 
{
	private:
		vector <shared_ptr<tuple<Key, Val, bool>>> table;
		int capacity;
		int hash(const Key& K) 
		{
			return Hash::hashFunction(K) % table.size();
		}
	public: 
		HashTable (const int &n = 1000) 
		{
			table.resize(n);
			capacity = 0;
		}

		void insert(Key K, Val V) 
		{
			int tableSize = table.size();
			int index = abs(hash(K));
			while (true) 
			{	
				if(!table[index] || (table[index] && get<2>(*table[index])))
				{ 
					table[index] = make_shared<tuple<Key, Val, bool>>(K, V, false);
					capacity++;
					return;
				}
				if (get<0>(*table[index]) == K) { get<1>(*table[index]) = V; }
				index = (index + 1) % tableSize;
			}
		}
		
		shared_ptr<tuple<Key, Val, bool>> find (const Key &k) 
		{	
			int tableSize = table.size();
			int index = abs(hash(k));
			int counter = 0;
			while(counter <= capacity) 
			{
				if (!table[index]) { return nullptr; }
				if (!get<2>(*table[index])) 
				{
					if(get<0>(*table[index]) == k) { return table[index]; } 
 					++counter;
				} 
				index = (index + 1) % tableSize;
			}
			return nullptr;
		}
		
		Val& operator[] (const Key& k) 
		{
			if (auto temp = find(k)) { return get<1>(*temp); }
			insert(k, Val{});
			return get<1>(*find(k));
		}
		
		void remove(const Key& k) 
		{
			auto temp = find(k);
	    	if (temp == nullptr) { return; }
	    	get<2>(*temp) = true;
			capacity--;
		}
  		
		int count() { return capacity; }
		
		bool isContainsKey(const Key &k) { return find(k) != nullptr; }
		
		int max_size() { return table.size(); }
		bool isEmpty() { return capacity == 0; }
    	
    	void Display() 
		{
			for (int i = 0; i < table.size(); ++i) 
			{
				if (table[i] && !get<2>(*table[i])) 
				{
					cout << i << " " << get<0>(*table[i]) << " " << get<1>(*table[i]) << endl;
				}
			}
		}	
};
#endif


