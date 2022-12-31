#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

string diversity(string str, int k) 
{
	if (str.size() < k)	return "impossible";
	unordered_set <char> s(str.begin(), str.end());
	return to_string(k - s.size());
}

main()
{
	vector <pair<string, int>> input { { "yandex", 6 }, { "google", 7 }, { "codelearn", 9 } };
	for (auto x : input) 
	{
		cout << "diversity(" << x.first << ", " << x.second << ") = " << diversity(x.first, x.second) << endl;
	}
	return 0;
}


