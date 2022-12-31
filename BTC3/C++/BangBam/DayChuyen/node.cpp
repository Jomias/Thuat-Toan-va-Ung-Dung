#ifndef node__cpp
#define node__cpp
#include <iostream>
using namespace std;

template <class Keys, class T>
class Node
{
	Keys key;
	T val;
	Node <Keys, T> *next;
	
	public:
		Node()
		{
			key = 0;
			val = 0;
			next = 0;
		}
		Node(Keys _key, T _val)
		{
			key = _key;
			val = _val;
			next = 0;
		}
		Keys getKey()
		{
			return key;
		}
		void setKey(Keys _key)
		{
			key = _key;
		}
		Node <Keys, T> *getNext()
		{
			return next;
		}
		void setNext(Node <Keys, T> *p)
		{
			next = p;
		}
		T getVal()
		{
			return val;
		}
		void setVal(T _val)
		{
			val = _val;
		}
		
};

#endif
