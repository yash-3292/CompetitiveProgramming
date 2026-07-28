#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> arr;
    for(ll i=0; i<n; i++){
        ll l;
        cin >> l;
        vector<ll> temp(l);
        for(ll j=0; j<l; j++) cin >> temp[j];
        arr.push_back(temp);
    }
    vector<ll> c(n);
    for(ll i=0; i<n; i++) cin >> c[i];
    vector<ll> presum(n);
    presum[0] = 0;
    for(ll i=1; i<n; i++){
        presum[i] += presum[i-1] + (ll)c[i-1] * (ll)arr[i-1].size();
    }
    k--;
    ll i = upper_bound(presum.begin(), presum.end(), k) - presum.begin() - 1;
    ll j = k - presum[i];
    j = j % arr[i].size();
    cout << arr[i][j] << endl;
}

int main(){
    solve();
    return 0;
}