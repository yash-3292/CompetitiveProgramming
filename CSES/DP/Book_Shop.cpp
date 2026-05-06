#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> h(n), s(n);
    for(int i=0; i<n; i++) cin >> h[i]; 
    for(int i=0; i<n; i++) cin >> s[i];
    vector<ll> next(x+1);
    vector<ll> cur(x+1);
    for(int sum=0; sum<=x; sum++) next[sum] = 0;
    for(int i=n-1; i>=0; i--){
        for(int sum=0; sum<=x; sum++){
            ll notTake = next[sum];
            ll take = 0;
            if(sum >= h[i]){
                take = s[i] + next[sum-h[i]];
            }
            cur[sum] = max(notTake, take);
        }
        next = cur;
    } 
    cout << next[x] << "\n";
    return 0;
}