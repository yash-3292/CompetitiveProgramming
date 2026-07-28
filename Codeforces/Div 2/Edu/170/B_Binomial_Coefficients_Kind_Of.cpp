#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void solve(){
    ll t;
    cin >> t;
    vector<ll> ni(t), ki(t);
    for(ll i=0; i<t; i++) cin >> ni[i];
    for(ll i=0; i<t; i++) cin >> ki[i];
    for(ll i=0; i<t; i++){
        ll ans = binpow(2,ki[i]);
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}