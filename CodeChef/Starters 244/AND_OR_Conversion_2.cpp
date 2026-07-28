#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

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

ll modInv(ll a){
    return binpow(a, mod - 2);
}

const ll maxN = 1e6+10;

ll fact[maxN];
ll invFact[maxN];

void preFact(){
    fact[0] = 1;
    for(ll i = 1; i < maxN; i++){
        fact[i] = (i * fact[i - 1]) % mod;
    }
    invFact[maxN - 1] = modInv(fact[maxN - 1]);
    for(ll i = maxN - 2; i >= 0; i--){
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

void solve(){
    ll n;
    cin >> n;
    string a;
    cin >> a;
    ll x = 0;
    for(ll i=0; i<n; i++){
        if(i == 0 || a[i] != a[i-1]){
            x++;
        }
    }
    ll ans = 0;
    for(ll i=1; i<=x; i++){
        ll val = fact[n-1];
        val = (val * invFact[n-i]) % mod;
        val = (val * invFact[i-1]) % mod;
        if(i < x){
            ans = (ans + 2 * val) % mod;
        } else{
            ans = (ans + val) % mod;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preFact();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}