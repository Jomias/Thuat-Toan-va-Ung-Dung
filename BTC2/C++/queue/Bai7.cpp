#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define For(i, a, b) for (ll i = (a); i <= (b); ++i)
#define Fo(i, a, b) for (ll i = (a); i < (b); ++i)
#define Ford(i, a, b) for (ll i = (a); i >= (b); --i)
#define int long long

vector <int> dx { 1, -1, 0, 0 };
vector <int> dy { 0, 0, -1, 1 };

bool isInRange(int i, int j, int n, int m) 
{
	return i >= 0 && j >= 0 && i < n && j < m;
}

int rotOrange(vector<vector<int>> &input) 
{
	queue <pair<int, int>> q;
	int n = input.size();
	int m = input[0].size();
	int freshOrangeCounts = 0;
	Fo(i, 0, n) 
	{
		Fo(j, 0, m) 
		{
			if (input[i][j] == 2)	q.push({i, j});
			if (input[i][j] == 1)	++freshOrangeCounts;
		}
	}
	if (!freshOrangeCounts)	return 0;
	
	int ans = -1;
	while (q.size()) 
	{
		int count = q.size();
		++ans;
		while (count--) 
		{
			pair<int, int> p = q.front();	q.pop();
			Fo (i, 0, 4) 
			{
				int X = p.first + dx[i];
				int Y = p.second + dy[i];
				if (isInRange(X, Y, n, m) && input[X][Y] == 1) 
				{
					--freshOrangeCounts;
					input[X][Y] = 2;
					q.push({X, Y});
				}
			}
		}
	}
	if (freshOrangeCounts)	return -1;
	return ans;
}
main()
{
	vector <vector<int>> matrix { 	{ 2, 1, 0, 2, 1 },
									{ 1, 0, 1, 2, 1 },
									{ 1, 0, 0, 2, 1	}	};	
									
	vector <vector<int>> matrix2 { 	{ 2, 1, 0, 2, 1 },
									{ 0, 0, 1, 2, 1 },
									{ 1, 0, 0, 2, 1	}	};	
									
	vector <vector<int>> matrix3 { 	{ 0, 0, 0 },
									{ 0, 0, 0 },
									{ 0, 0, 0 }	};	
	cout << rotOrange(matrix3);
	return 0;
}


