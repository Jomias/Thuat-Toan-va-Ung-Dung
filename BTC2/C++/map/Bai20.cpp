#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

int largestElement(vector<int> v) 
{
	map<int, int> m;
	for (auto x : v)	++m[x];
	int frequency = LLONG_MAX, res;
	for (auto x : m) 
	{
		if (x.second <= frequency) 
		{
			frequency = x.second;
			res = x.first;
		}
	}
	return res;
}
main()
{
	vector <int> arr1 { 2, 2, 4, 4, 7, 7, 7 }, arr2 { 1, 3, 4, 5, 5 };
	cout << largestElement(arr1) << endl;
	cout << largestElement(arr2);
	return 0;
}


