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

int n,k;
bool cmp(ll a,ll b){
	
	if(a%k!=b%k) return a%k>b%k;
	else return a<b;
}

signed main(){
	fastio;
	cin>>n>>k;
	ll a[n+5]; 
	fr(i,1,n) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	fr(i,1,n) cout<<a[i]<<" ";
	
	
	
}
