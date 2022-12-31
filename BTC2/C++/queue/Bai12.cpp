#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector <int> biggestVal(vector<int> input, int k) 
{
	deque<int> dq;
	vector<int> ans;
	Fo(i, 0, k) 
	{	
		while(dq.size() && input[i] > input[dq.back()])	dq.pop_back();
		dq.push_back(i);
	}
	ans.push_back(input[dq.front()]);
	Fo(i, k, input.size())
	{
		if (dq.front() <= i - k) 	dq.pop_front();
		while(dq.size() && input[i] > input[dq.back()])	dq.pop_back();
		dq.push_back(i);
		ans.push_back(input[dq.front()]);
	}	
	return ans;
}
main()
{
	vector<int> arr { 1, 2, 3, 1, 4, 5, 2, 3, 6 };
	int k = 3;
	vector<int> ans = biggestVal(arr, k);
	for (auto i : ans)	cout << i << " ";
	return 0;
}


