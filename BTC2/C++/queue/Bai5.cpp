#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector <int> basePrimeNumbers { 2, 3, 5, 7 };
vector <int> nextPrimeDigit { 1, 3, 7, 9 };
bool isPrime(int n) 
{
	if (n <= 3)	return n > 1;
	if (n % 2 == 0 || n % 3 == 0)	return 0;
	for (int i = 5; i * i <= n; ++i) 
	{
		if (n % i == 0 || n % (i + 2) == 0)	return 0;
	}
	return 1;
}

vector <int> superPrimeNumber(int n) 
{
	queue <int> q;
	vector <int> v;
	for (auto x : basePrimeNumbers)	q.push(x);
	while (q.size()) 
	{
		for (auto x : nextPrimeDigit) 
		{
			int k = q.front() * 10 + x;
			if (k > n)	break;
			if (isPrime(k))	 q.push(k);
		}
		v.push_back(q.front());
		q.pop();
	}
	return v;
}

main()
{
	int n = 30;
	vector <int> v = superPrimeNumber(n);
	for (auto x : v)	cout << x << " ";
	
	return 0;
}


