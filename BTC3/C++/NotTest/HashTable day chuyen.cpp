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

vector <ll> hashTable[1000];
int hashTbSize=1000;

int hashFunc(ll n){
	return n%hashTbSize;
}

void insert(ll n){
	int idx=hashFunc(n);
	hashTable[idx].pb(n);
}

void search(ll n){
	int idx=hashFunc(n);
	for(int i=0;i<hashTable[idx].size();i++){
		if(n== hashTable[idx][i]){
			cout<<n<<endl;
			return;
		}
	}
	
	cout<<n<<" not found"<<endl;
}

signed main(){
	fastio;
	
	
	
}
