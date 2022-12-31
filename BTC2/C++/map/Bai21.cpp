#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector<int> countPrefix(vector<string> contacts, vector<string> names) 
{
	unordered_map <string, int> m;
	vector <int> ans;
	for (auto contact : contacts) 
	{
		string s = "";
		for (auto i : contact) 
		{
			s += i;
			++m[s];
		}
	}
	for (auto name : names) ans.push_back(m[name]);
	return ans;
}
main()
{
	vector <string> contacts { "Codelearn", "Codewar" }, names { "Code", "Codel", "io" };
	vector <int> v = countPrefix(contacts, names);
	for (auto i : v)	cout << i << " ";
	return 0;
}


