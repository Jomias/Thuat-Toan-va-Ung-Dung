#ifndef sList__cpp
#define sList__cpp
#include "node.cpp"
#include <iostream>
using namespace std;

template <class Keys, class T>
class sList
{
	long sz;
	Node <Keys, T> *head;
	Node <Keys, T> *trail;
	
	public:
		sList()
		{
			head = trail = 0;
			sz = 0;
		}
		long size()
		{
			return sz;
		}
		bool empty()
		{
			return sz == 0;
		}
	    Node <Keys, T> *insertLast(Keys k, T v)
		{
	        Node <Keys, T> *p;
	        p = new Node <Keys, T> (k, v);
	        if(empty())
			{
	            head = trail = p;
	        }
	        else
			{
	            trail -> setNext(p);
	            trail = p;
	        }
	        sz++;
	        return p;
	    }

	    void replace(Node <Keys, T> *p, Keys k, T v)
		{
	        p -> setKey(k);
	        p -> setVal(v);
	    }
	    
	    void remove(Node <Keys, T> *p)
		{
	        Node <Keys, T> *p1;
	        if(p == head)
			{	
	            if(size() == 1)	head = trail = 0;
	            else	head = head -> getNext();
	            sz--;
	        }
	        else
			{
	            p1 = head;
	            while(p1 -> getNext() != p) p1 = p1 -> getNext();
	            if(p1 != 0)
				{
	                if(p != trail)	p1 -> setNext(p -> getNext());
	                else
					{
	                    trail = p1;
	                    p1 -> setNext(0);
	                }
	                sz--;
	            }
	        }
	        delete p;
	    }
	    
	    Node <Keys, T> *getNode(Keys k)
		{
	        Node <Keys, T> *p = head;
	        while(p != 0 && p -> getKey() != k)	p = p -> getNext();
	        return p;
	    }
	    
	    Node <Keys, T> *getHead()
	    {
	    	return head;
		}
};

#endif
