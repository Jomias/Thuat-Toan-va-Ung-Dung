#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

class Compare 
{
	public:
		bool operator() (const pair<int, int> &a, const pair<int, int> &b) 
		{
			return a.first * a.first + a.second * a.second > b.first * b.first + b.second * b.second;
		}
};

vector<pair<int, int>> closetPoints(vector<pair<int, int>> input, int k)  
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, Compare> pq;
	vector<pair<int, int>> ans;
	for (auto x : input)	pq.push(x);
	Fo(i, 0, k) 
	{
		ans.push_back(pq.top());
		pq.pop();
	}
	return ans;
}

main()
{
	vector<pair<int, int>> input = { { 1, 0 }, { 2, 1 }, { 3, 6 }, { -5, 2 }, { 1, -4 } };
	int k = 3;
	vector<pair<int, int>> ans = closetPoints(input, k);
	for (auto x : ans)	cout << "(" << x.first << ", " << x.second << ") ";
	
	return 0;
}


