#include <bits/stdc++.h>
using namespace std;
template <class T, class CMP = less <T>>
class Priority_queue 
{
	vector<T> v;
	CMP compare;
	void heapify (int k) 
	{
		int n = v.size();
		int p = 2 * k + 1;
		if (p >= n)	return;
		if (p + 1 < n && compare(v[p], v[p+1])) ++p;
		if (!compare(v[k], v[p]))	return;
		swap(v[k], v[p]);
		heapify(p);
	}
	public :
		Priority_queue() {}
		int size() 
		{
			return v.size();
		}
		bool empty() 
		{
			return v.size() == 0;
		}
		T top() 
		{
			return v[0];
		}
		void push(T x) 
		{
			int k = v.size();
			v.push_back(x);
			while (k > 0 && compare(v[(k-1)/2], v[k])) 
			{
				swap(v[(k-1)/2], v[k]);
				k = (k - 1) / 2;
			}
		}
		void pop() 
		{
			v[0] = v[v.size() - 1];
			v.pop_back();
			heapify(0);
		}
		
};

int main()
{
	int a[] = {5, 10, 15, 20, 1, 2, 3, 5, 177, 112};
	Priority_queue<int> pq;
	for (auto i : a) 
	{
		pq.push(i);	
	}
	while(pq.size())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}


