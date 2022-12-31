#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector <int> firstNegative(vector <int> arr, int k) 
{
	queue <int> q;
	vector <int> ans;
	Fo(i, 0, k - 1)	if (arr[i] < 0)	q.push(i);
	Fo(i, k - 1, arr.size()) 
	{
		if (arr[i] < 0)	q.push(i);
		while (q.size() && q.front() < i - k + 1)	q.pop();
		ans.push_back(q.empty() ? 0 : arr[q.front()]);
	}
	return ans;
}
main()
{
	vector <int> arr { -8, 2, 3, -6, 10 };
	int k = 2;
	vector <int> ans = firstNegative(arr, k);
	for (auto x : ans)	cout << x << " ";
	return 0;
}


