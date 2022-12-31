#ifndef hashTable__cpp
#define hashTable__cpp
#include"sList.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int Hash(string key, int n)
{
	int sum = 0;
	for(int i = 0; i < key.length(); i++)	sum += key[i];
	return sum % n;
}	

template <class Keys, class T>
class hashTable
{
    int N;
    sList <Keys, T> *table;
    
    public:
        hashTable(int n)
		{
            N = n;
            table = new sList <Keys, T> [N + 1];
        }
        Node <Keys, T> *Add(Keys key, T obj, int (*hash)(Keys, int))
		{
            Node <Keys, T> *p;
            int h = hash(key, N);
            p = table[h].getNode(key);
            if(p == 0)	return table[h].insertLast(key, obj);
            else	return 0;
        }
        void Remove(Keys key, int (*hash)(Keys, int))
		{
            Node <Keys,T> *p;
            int h = hash(key, N);
            p = table[h].getNode(key);
            if(p != 0)	table[h].remove(p);
        }
        Node <Keys, T> *Find(Keys key, int (*hash)(Keys, int))
		{     
            int h = hash(key, N);
            return table[h].getNode(key);
        }
        bool Contains(Keys key, int (*hash)(Keys, int))
		{
            int h = hash(key, N);
            return table[h].getNode(key);
        }
        long Count()
		{
            long s = 0;
            for(int i = 0; i < N; i++)	s += table[i].size();
            return s;
        }
        void Travel(string s)
		{
			ofstream ofs(s);
			Node <Keys, T> *x;
			for(int i = 0; i < N; i++)
			{
				x = table[i].getHead();
				while(x != 0) 
				{
					ofs << x -> getKey() << endl << x -> getVal() << endl;
					x = x -> getNext();
				}
			}
			ofs.close();
		}
};

#endif
