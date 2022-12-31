#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector<bool> mergeProducts(vector<string> A, vector<string> B) 
{
	unordered_map <string, int> m;
	vector <bool> ans;
	for (auto x : A)	++m[x];
	for (auto x : B)	ans.push_back(m.find(x) == m.end());
	return ans;
}
main()
{
	vector <string> A { "Banana", "Banana", "Apple" }, B { "Orange", "Apple", "Banana", "Watermelon" };
	vector <bool> v = mergeProducts(A, B);
	for (auto i : v)	cout << i << " ";
	return 0;
}


