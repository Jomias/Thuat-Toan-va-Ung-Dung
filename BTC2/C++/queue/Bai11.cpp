#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector<int> biggestProducts(vector<int> input)  
{
	priority_queue<int> pq;
	vector<int> bg(3);
	vector<int> ans { input[0], input[0] * input[1] };
	Fo(i, 0, 2)	pq.push(input[i]);
	Fo(i, 2, input.size()) 
	{
		pq.push(input[i]);
		Fo(j, 0, 3) 
		{
			bg[j] = pq.top();
			pq.pop();
		}
		ans.push_back(bg[0] * bg[1] * bg[2]);
		Fo(j, 0, 3)	pq.push(bg[j]);	
	}
	return ans;
}

main()
{
	vector<int> input { 0, 1, 3, 5, 6, 2, 7, 2, 3, 8 };
	for (auto x : biggestProducts(input))	cout << x << " ";
	return 0;
}


