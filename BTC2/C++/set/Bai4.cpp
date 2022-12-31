#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector<string> getDistinctProducts(vector<string> &products) 
{
	set<string> s(products.begin(), products.end());
	vector <string> v(s.begin(), s.end());
	return v;
}

main()
{
	vector <string> products { "watermelon", "grapes", "grapes", "apple", "grapes" };
	products = getDistinctProducts(products);
	for (auto x : products)	cout << x << endl;
	return 0;
}


