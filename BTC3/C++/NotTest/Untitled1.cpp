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

int sum(ll n){
	int s=0;
	while(n){
		s+=n%10;
		n/=10;
	}
	return s;
}

bool cmp(ll a,ll b){
	if(sum(a)!=sum(b)) return sum(a)<sum(b);
	else{
		return a<b;
	}
}

signed main(){
	fastio;
	int n;cin>>n;
	ll a[n];
	fr(i,1,n) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	fr(i,1,n) cout<<a[i]<<' ';
	
	
	
}
