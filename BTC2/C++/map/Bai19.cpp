#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

bool checkSum(vector<int> arr, int sum) 
{
	unordered_map <int, bool> m;
	Fo(i, 0, arr.size())
	{
		if (m.find(sum - arr[i]) != m.end())	return 1;
		m[arr[i]] = 1;
	}
	return 0;
}
main()
{
	vector<int> arr1 { 2, 4, -1, 9, 8 }, arr2 { 2, 5, 3, 8, 9}, arr3 { 4, 7, 3, 5 };
	int sum1 = 6, sum2 = 3, sum3 = 6;
	cout << checkSum(arr1, sum1) << endl;
	cout << checkSum(arr2, sum2) << endl;
	cout << checkSum(arr3, sum3) << endl;
	return 0;
}


