#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rfr(i,a,b) for(int i=b;i>=a;i--)
#define frk(i,a,b,k) for(int i=a;i<=b;i+=k)
#define rfrk(i,a,b,k) for(int i=b;i>=a;i-=k)
#define endl "\n"
#define pb push_back
ll mod=1e9+7;

int n;
signed main(){
	fastio;
	map<ll,int> m;
	ll a[n+5];
	fr(i,1,n){
		cin>>a[i];
		m[a[i]]++;
	} 
	ll Max=-mod;
	for(auto it:Max){
		Max=max(Max,it.second);
	}
	sort(a+1,a+n+1);
	cout<<a[(n+1)/2];
}
