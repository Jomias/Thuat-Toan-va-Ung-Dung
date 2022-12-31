#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

int biggestSum(vector<int> input, int k) 
{
	deque<int> dq1, dq2;
	int ans = 0;
	Fo(i, 0, k) 
	{	
		while(dq1.size() && input[i] > input[dq1.back()])	dq1.pop_back();
		while(dq2.size() && input[i] < input[dq2.back()])	dq2.pop_back();
		dq1.push_back(i);
		dq2.push_back(i);
	}
	ans += input[dq1.front()] + input[dq2.front()];
	Fo(i, k, input.size())
	{
		if (dq1.front() <= i - k) 	dq1.pop_front();
		if (dq2.front() <= i - k) 	dq2.pop_front();
		while(dq1.size() && input[i] > input[dq1.back()])	dq1.pop_back();
		while(dq2.size() && input[i] < input[dq2.back()])	dq2.pop_back();
		dq1.push_back(i);
		dq2.push_back(i);
		ans += input[dq1.front()] + input[dq2.front()];
	}	
	return ans;
}

main()
{
	vector<int> arr { 2, 5, -1, 7, -3, -1, -2 };
	int k = 4;
	cout << biggestSum(arr, k);
	return 0;
}


