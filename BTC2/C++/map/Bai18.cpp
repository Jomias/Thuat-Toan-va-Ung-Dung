#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

int sumOfCommon(vector<int> arr1, vector<int> arr2) 
{
	unordered_map<int, bool> m;
	int sum = 0;
	for (auto x : arr1)	m[x] = 1;
	for (auto x : arr2) 
	{
		if (m[x] == 1) 
		{
			sum += x;
			m[x] = 0;
		}
	}
	return sum;
}
main()
{
	vector <int> arr1 { 6, 7, 5, 4, 6, 8 };
	vector <int> arr2 { 2, 5, 7, 5, 3 };
	cout << sumOfCommon(arr1, arr2) << endl;
	return 0;
}


