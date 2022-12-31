#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

void solve(vector<int> input) 
{
	int maxFrequency = 0;
	map<int, int> m;
	for (auto x : input)	maxFrequency = max(maxFrequency, ++m[x]);
	for (auto x : m)	if (x.second == maxFrequency)	cout << x.first << " ";
	cout << endl << "FREQUENCY: " << maxFrequency;
}
main()
{
	vector <int> a { 4, 7, 2, 8, 4, 8, 3, 2 };
	solve(a);
	return 0;
}


