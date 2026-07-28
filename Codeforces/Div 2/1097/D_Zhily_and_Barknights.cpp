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

static bool comp(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
    return p1.first * p2.second < p2.first * p1.second;
}

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    vector<pair<ll,ll>> arr;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j) arr.push_back({b[i], b[j]});
        }
    }
    sort(arr.begin(), arr.end(), comp);
    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            pair<ll,ll> x = {a[i], a[j]};
            ll ind = lower_bound(arr.begin(), arr.end(), x, comp) - arr.begin();
            ind = ind % mod;
            ans = (ans + ind) % mod;
        }
    }
    ll den = n * (n-1);
    ans = (ans * modinv(den)) % mod;
    cout << ans << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}