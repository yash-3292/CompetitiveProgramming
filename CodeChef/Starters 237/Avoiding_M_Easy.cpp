#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

ll modinv(ll n){
    return binpow(n, mod-2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll ans = binpow(n+1, n);
        ll val1 = 1;
        for(ll i=1; i<=m; i++){
            val1 = (val1 * i) % mod;
        }
        ll rem = n-m;
        vector<ll> arr(rem);
        if(rem){
            arr[rem-1] = n;
            for(ll i=rem-2; i>=0; i--){
                arr[i] = arr[i+1]-1;
            }
            for(ll i=rem-2; i>=0; i--){
                arr[i] = (arr[i] * arr[i+1]) % mod;
            }
        }
        ll val2 = 0;
        for(ll i=0; i<=rem; i++){
            ll x = i+1;
            if(i != rem){
                x = (x * n) % mod;
                x = (x * arr[i]) % mod;
            } 
            val2 = (val2 + x) % mod;
        }
        ll val = (val1 * val2) % mod;
        ans = (ans - val + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}