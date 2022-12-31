#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

string secRank(vector<int> v) 
{
	set <int> s(v.begin(), v.end());
	return (v.size() < 2 || s.size() == 1)  ? "NO" : to_string(*(++s.begin()));
}
main()
{
	vector<int> inputVector { 1, 3, 3, 2, 2 };
	cout << secRank(inputVector);
	return 0;
}


