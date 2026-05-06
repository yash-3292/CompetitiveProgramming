#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    a = a % mod;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % mod;
        b >>= 1;
        a = (a*a) % mod;
    }
    return res;
}

ll inv(ll a){
    return binpow(a, mod-2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        ll fraction = inv((n*(n-1))/2);
        ll p = (m * inv((n*(n-1))/2)) % mod;
        ll ans = 0;
        ll sum = 0;
        for(ll i=0; i<m; i++){
            ll a, b, f;
            cin >> a >> b >> f;
            sum = (sum+f) % mod;
        }
        for(ll i=0; i<k; i++){
            ans = (ans+(sum*fraction)%mod) % mod;
            sum = (sum + p) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}