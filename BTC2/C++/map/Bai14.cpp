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
	map <int, int> m;
	for (auto x : input)	++m[x];
	for (auto i : m)	cout << i.first << ": " << i.second << endl;
}

main()
{
	vector <int> input { 5, 6, 5, 1, 2, 3, 3, 2, 1, 5, 7, 7, 7, 1, 5};
	solve(input);
	return 0;
}


