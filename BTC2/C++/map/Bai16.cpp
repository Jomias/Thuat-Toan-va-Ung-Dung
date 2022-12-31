#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector <string> countChar(std::string str) 
{
	map<char, int> m;
	vector<string> v;
	for (auto x : str)	++m[x];
	for (auto x : m) 
	{
		string temp =  "";
		temp += x.first; 
		temp += " " + to_string(x.second);
		cout << temp << endl;
		v.push_back(temp);
	}
	return v;
}

main()
{
	string s1 = "aacccd";
	string s2 = "aabbbca";
	vector <string> v1 = countChar(s1), v2 = countChar(s2);
	for (auto x : v1)	cout << x << " ";
	cout << endl;
	for (auto x : v2)	cout << x << " ";
	cout << endl;
	return 0;
}


