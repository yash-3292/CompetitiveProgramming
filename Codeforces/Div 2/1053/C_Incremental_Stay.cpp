#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(2*n);
    for(ll i=0; i<2*n; i++) cin >> arr[i];
    vector<ll> presum(2*n);
    presum[0] = arr[0];
    for(ll i=1; i<2*n; i++) presum[i] = presum[i-1] + arr[i];
    vector<ll> arr1(2*n), arr2(2*n);
    arr1[0] = -1*arr[0];
    arr2[0] = arr[0];
    for(ll i=1; i<2*n; i++){
        ll x;
        if(i&1){
            x = arr[i];
        } else{
            x = -1*arr[i];
        }
        arr1[i] = arr1[i-1] + x;
        arr2[i] = arr2[i-1] - x;
    }
    for(ll k=1; k<=n; k++){
        ll ans = 0;
        ans -= presum[k-1];
        ans += presum[2*n-1] - presum[2*n-1-k];
        ll l = k;
        ll r = 2*n-1-k;
        if(k&1){
            ans += arr1[r];
            if(l != 0) ans -= arr1[l-1];
        } else{
            ans += arr2[r];
            if(l != 0) ans -= arr2[l-1];
        }
        cout << ans << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}