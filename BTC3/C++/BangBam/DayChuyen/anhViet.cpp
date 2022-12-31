#ifndef anhViet__cpp
#define anhViet_cpp
#include <iostream>
#include <fstream>
#include"hashTable.cpp"
using namespace std;
		
class anhViet 
{
	hashTable <string, string> *Dic;
	public:
		
		anhViet() 
		{
			Dic = new hashTable <string, string> (101);
		}
		
		bool addWord(string word, string mean) 
		{
			return	Dic -> Add(word, mean, Hash);
		}
		
		bool editWord(string word, string newMean) 
		{
			Node <string, string> *p;
			p = Dic -> Find(word, Hash);			
			if(p == 0)	return 0;
			else
			{
				p -> setVal(newMean);
				return 1;
			}
		}
		
		void removeWord(string word) 
		{
			Dic -> Remove(word, Hash);		
		}
		
		Node <string, string> *findWord(string word) 
		{
			return Dic -> Find(word, Hash);
		}
		
 		void readFile()
		{
			ifstream ifs("tudien.txt");
			string word, mean;
			while(!ifs.eof())
			{
				getline(ifs, word);
				getline(ifs, mean);
				Dic -> Add(word, mean, Hash);
			}
			ifs.close();
		}
		
		void exportFile(string s) 
		{
			Dic -> Travel(s);
		}
};

#endif
