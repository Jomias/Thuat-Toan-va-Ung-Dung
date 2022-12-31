#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

int getStart(vector<pair<int, int>> input) 
{
	int start = 0, fuel = 0, lost = 0;
	Fo(i, 0, input.size()) 
	{
		fuel += input[i].first - input[i].second;
		if (fuel < 0) 
		{
			start = i + 1;
			lost += fuel;
			fuel = 0;
		}
	}
	return fuel + lost >= 0 ? start : -1;
}
main()
{
	vector<pair<int, int>> input { {1, 2}, {1, 2}, {1, 2}, {4, 1} };
	cout << getStart(input);
	return 0;
}


