#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n){
    ll ans = 0;
    if(n&2) ans = 1;
    if(n&1){
        n = 1;
    }
    ans = (ans^n);
    return ans;
}

ll f1(ll n, ll i, ll k){
    if(k > n) return 0;
    ll x = ((n-k)>>i);
    int flag = 1;
    if(x&1) flag = 0; 
    ll val = f(x);
    val = (val<<i);
    if(flag) val = (val^k);
    return val;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll l, r, i, k;
        cin >> l >> r >> i >> k;
        k = (k%(1<<i));
        ll ans = (f(r) ^ f(l-1));
        ll val = (f1(r, i, k) ^ f1(l-1, i, k));
        ans = (ans^val);
        cout << ans << endl;
    }
    return 0;
}