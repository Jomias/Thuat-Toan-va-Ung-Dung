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

// tham do bac 2

ll hashTable[1000];
int sz=1000;

int hashFunc(ll n){
	return n%sz;
}

void insert(ll n){
	int idx=hashFunc(n);
	int h=1;
	while(hashTable[idx]!=0){
		idx=(idx+ h*h)%sz;
		h++;
	}
	hashTable[idx]=n;

}

int search(ll n){
	int h=1, idx=hashFunc(n);
	while(hashTable[idx]!=0 && hashTable[idx]!=n){
		idx=(idx+h*h)%sz;
		h++;
	}
	if(hashTable[idx]==n) return n;
	else return -1;
}
signed main(){
	fastio;

}
