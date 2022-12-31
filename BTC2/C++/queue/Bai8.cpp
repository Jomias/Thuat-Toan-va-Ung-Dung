#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

int solveNonQueue(int n) 
{
	int x = 1, val = n;
    while(val - (x * 5) > 0)
    {
        val -= x * 5;
        x *= 2;
    }
    return (val + x - 1) / x;
}

int solveWithQueue(int n) 
{
	queue <pair<int, int>> q;
	for (auto x : { 1, 2, 3, 4, 5 })	q.push({x, 1});
	while(n > q.front().second) 
	{
		n -= q.front().second;
		q.push({q.front().first, q.front().second * 2});
		q.pop();
	}
	return q.front().first;
}
main()
{
	int n = 15999998;
	cout << solveNonQueue(n) << endl;
	cout << solveWithQueue(n);
	return 0;
}


