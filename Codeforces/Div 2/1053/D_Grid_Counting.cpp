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

ll modinv(ll a){
    return binpow(a, mod-2);
}

const ll maxN = 1e6+10;
ll fact[maxN];
ll invFact[maxN];

void preFact(){
    fact[0] = 1;
    invFact[0] = 1;
    for(ll i=1; i<maxN; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invFact[maxN-1] = modinv(fact[maxN-1]);
    for(ll i=maxN-2; i>=0; i--){
        invFact[i] = (invFact[i+1] * (i+1)) % mod;
    }
}

ll nCr(ll n, ll r){
    ll ans = 1;
    ans = (ans * fact[n]) % mod;
    ans = (ans * invFact[r]) % mod;
    ans = (ans * invFact[n-r]) % mod;
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll cnt = 0;
    for(int i=0; i<n; i++) cnt += arr[i];
    if(cnt != n){
        cout << 0 << endl;
        return;
    }
    ll ans = 1;
    ll x = 0;
    for(ll i=n; i>=1; i--){
        if(n&1){
            if((n+1)/2 == i) x++;
            else if(i < (n+1)/2) x += 2;
        } else{
            if(i <= (n+1)/2) x += 2;
        }
        if(arr[i-1] > x){
            cout << 0 << endl;
            return;
        }
        ans = (ans * nCr(x, arr[i-1])) % mod;
        x -= arr[i-1];
    }
    if(x > 0){
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}

int main(){
    preFact();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}