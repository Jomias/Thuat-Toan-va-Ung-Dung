#include <bits/stdc++.h>
using namespace std;
template <class T, class CMP = less <T>>
class Priority_queue 
{
	T* buf;
	int cap, n;
	CMP compare;
	void heapify (int k) 
	{
		int p = 2 * k + 1;
		if (p >= n)	return;
		if (p + 1 < n && compare(buf[p], buf[p+1])) ++p;
		if (!compare(buf[k], buf[p]))	return;
		swap(buf[k], buf[p]);
		heapify(p);
	}
	public :
		Priority_queue() 
		{
			buf = nullptr;
			cap = n = 0;
		}
		~Priority_queue() 
		{
			if (buf)	delete[] buf;
		}
		int size() 
		{
			return n;
		}
		bool empty() 
		{
			return n == 0;
		}
		T top() 
		{
			return buf[0];
		}
		void push(T x) 
		{
			if (cap == n) 
			{
				cap = 2 * cap + 1;
				T * temp = new T[cap];
				for (int i = 0; i < n; ++i)	temp[i] = buf[i];
				if (buf)	delete[] buf;
				buf = temp;
			}
			int k = n;
			buf[n++] = x;
			while (k > 0 && compare(buf[(k-1)/2], buf[k])) 
			{
				swap(buf[(k-1)/2], buf[k]);
				k = (k - 1) / 2;
			}
		}
		void pop() 
		{
			--n;
			buf[0] = buf[n];
			heapify(0);
		}
};

int main()
{
	Priority_queue<int> Q;
	for(int x:{43,75,24,53,58,62,24,63,146,363,35,2,75,458,34,52,86,79,61}) Q.push(x);
	while(Q.size())
	{
		cout<<Q.top()<<" ";
		Q.pop();
	}
}


