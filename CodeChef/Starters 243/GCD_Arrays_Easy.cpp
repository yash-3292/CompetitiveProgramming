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

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> coprime;
    for(ll i=2; i<=m; i++){
        for(ll j=i+1; j<=m; j++){
            if(__gcd(i, j) == 1){
                coprime.push_back({i,j});
            }
        }
    }
    ll ans = 0;
    for(auto it : coprime){
        vector<ll> f1, f2;
        for(ll i=2; i*i<=it.first; i++){
            if(it.first%i == 0){
                f1.push_back(i);
                if(i != it.first/i) f1.push_back(it.first/i);
            }
        }
        for(ll i=2; i*i<=it.second; i++){
            if(it.second%i == 0){
                f2.push_back(i);
                if(i != it.second/i) f2.push_back(it.second/i);
            }
        }
        for(auto a : f1){
            for(auto b : f2){
                if(a*b > m) continue;
            }
        }
    }
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