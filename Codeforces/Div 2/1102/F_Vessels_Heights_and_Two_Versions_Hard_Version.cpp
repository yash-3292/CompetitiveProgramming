#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> h(n);
    for(ll i=0; i<n; i++) cin >> h[i];
    ll maxi = 0;
    for(ll i=0; i<n; i++) maxi = max(maxi, h[i]);
    vector<ll> arr;
    for(ll i=0; i<n; i++){
        arr.push_back(h[i]);
    }
    for(ll i=0; i<n; i++){
        arr.push_back(h[i]);
    }
    ll i = 0;
    ll j = n-1;
    ll preSum = 0;
    ll preMax = 0;
    ll sufSum = 0;
    ll sufMax = 0;
    for(ll i=0; i<n-1; i++){
        preMax = max(preMax, arr[i]);
        preSum += preMax;
    }
    for(ll i=n-1; i>=1; i--){
        sufMax = max(sufMax, arr[i]);
        sufSum += sufMax;
    }
    while(i < n){
        ll ans = sufSum + preSum - (n-1) * maxi;
        cout << ans << endl;
        i++;
        j++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}