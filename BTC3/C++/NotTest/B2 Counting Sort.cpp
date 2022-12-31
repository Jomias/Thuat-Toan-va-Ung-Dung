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

void countSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
  
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
  
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
  
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
  
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

signed main(){
	fastio;

}