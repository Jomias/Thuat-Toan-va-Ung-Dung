#include "hashTable.h"
using namespace std;
class Dictionary 
{
	private:
		HashTable <string, string> Dic;
	public:
		bool addWord(string word, string mean) 
		{
			if (Dic.find(word)) { return 0; }
			Dic[word] = mean; 
			return 1;
		}

		void removeWord(string word) 
		{
			Dic.remove(word);		
		}

		void editWord(string word, string newMean) 
		{
			if(!Dic.find(word)) { return; }
			Dic[word] = newMean;		
		}

		string findWord(string word) 
		{
			if (Dic.find(word) == nullptr ) { return "Chua co trong tu dien"; }
			return Dic[word];
		}
		
 		void readFile()
		{
			ifstream ifs("tudien.txt");
			string word, mean;
			while(!ifs.eof())
			{
				getline(ifs, word);
				getline(ifs, mean);
				addWord(word, mean);
			}
			ifs.close();
		}
		void showDictionary() 
		{
			Dic.Display();
		}
};

int main()
{
	Dictionary x;
	x.readFile();
	x.showDictionary();
	cout << x.findWord("fact") << "\n";
	x.editWord("fact", "Nghia da sua doi");
	x.removeWord("brother");
	cout << x.findWord("fact") << "\n";
	cout << "****************\n";
	x.showDictionary();
	
	return 0;
}


