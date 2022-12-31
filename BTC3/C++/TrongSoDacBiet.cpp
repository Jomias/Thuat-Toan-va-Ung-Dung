#include<bits/stdc++.h>
using namespace std;
int k = 2;

bool cmp(int a, int b) {
    if (a % k == b % k) {
        return a < b;
    }
	return a % k > b % k;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    sort(v.begin(), v.end(), cmp);

	for (auto x : v) {
		cout << x << " ";
	}
}