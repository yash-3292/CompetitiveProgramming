#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<ll> preXor(n);
    preXor[0] = arr[0];
    for(ll i=1; i<n; i++){
        preXor[i] = (preXor[i-1] ^ arr[i]);
    }
    if(n%2 == 0){
        ll val = preXor[((n+1)/2) - 1];
        arr.push_back(val);
        ll p = (preXor[n-1] ^ val);
        preXor.push_back(p);
        n++;
    }
    ll total = preXor.back();
    if(l <= n){
        cout << arr[l-1] << endl;
        return;
    }
    ll temp = l/2;
    ll ans = 0;
    while(temp > n){
        ans = (ans ^ total);
        if(temp&1){
            break;
        }
        temp /= 2;
    }
    if(temp <= n) ans = (ans ^ preXor[temp-1]);
    cout << ans << endl;
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