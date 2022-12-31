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

// bang bam tuyen tinh 

ll hashTable[1000];
int sz=1000;

int hashFunc(ll n){
	return n%sz;
}

void insert(ll n){
	int idx=hashFunc(n);
	while(hashTable[idx]!=0){
		idx=(idx+1)%sz;
	}
	hashTable[idx]=n;
	
}

ll search(ll n){
	int idx=hashFunc(n);
	while(hashTable[idx]!=n && hashTable[idx]!=0){
		idx=(idx+1)%sz;
	}
	if(hashTable[idx]==n){
		return n;
	} 
	else return -1;
	
}

signed main(){
	fastio;
	
}
