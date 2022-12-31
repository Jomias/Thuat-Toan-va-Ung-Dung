#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

bool customCompare(pair<char, int> &a, pair<char, int> &b) 
{
	if (a.second == b.second)	return a.first < b.first;
	return a.second > b.second;
}
string modifyString(string s) 
{
	unordered_map<char, int> m;
	for (auto x : s)	++m[x];
	string ans = "";
	vector <pair<char, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), customCompare);

	for (auto x : v)	ans += x.first;
	return ans;		
}
main()
{
	string s1 = "codelearn";	cout << modifyString(s1) << endl;
	string s2 = "helloworld";	cout << modifyString(s2);
	return 0;
}


