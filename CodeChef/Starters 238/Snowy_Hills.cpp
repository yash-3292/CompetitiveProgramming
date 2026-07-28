#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, k, h;
    cin >> n >> k >> h;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll sum = 0;
    for(ll i=0; i<n-1; i++){
        ll x = arr[i];
        ll y = arr[i+1];
        ll val = 1e12;
        if(x >= y){
            val = (x-y) * k;
        } else{
            ll d = 1;
            while(x%d == 0) d *= 2;
            d/=2;
            ll prev = x;
            while(x < y){
                prev = x;
                x += d;
                while(x%(2*d) == 0) d *= 2;
            }
            val = min(val, (x-y) * k);
            val = min(val, (y-prev) * h);
            // cout << prev << " " << y << " " << val << endl;
        }
        sum += val;
    }
    cout << sum << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}