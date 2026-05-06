#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res*a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll ans = binpow(m, n);
        ans = ((ans * (m+1)) % mod * (ll)500000004) % mod;
        ans = (ans * n) % mod;
        ll rem = 0;
        for(int i=1; i<=m; i++){
            ll val = binpow(m-i+1, n) - binpow(m-i, n);
            val = (val * (ll)i) % mod;
            rem = (rem + val) % mod;
        }
        ans = (ans - rem) % mod;
        ans = (ans + mod) % mod;
        cout << ans << endl;
    }
    return 0;
}