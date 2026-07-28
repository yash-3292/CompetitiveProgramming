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
        a = (a*a)%mod;
    }
    return res;
}

ll modInv(ll a){
    return binpow(a, mod-2);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll val2 = 1;
    for(ll i=0; i<k; i++){
        if(i != 0){
            val2 = (val2 * (n-k+i-1)) % mod;
            val2 = (val2 * modInv(i)) % mod;
        }
        ll val1 = binpow(k-i, k);
        ll val = (val1 * val2) % mod;
        ans = (ans + val) % mod;
    }
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