#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll a, ll b){
    if(a > b) return 0;
    if(a&1){
        return (b-a+1)/2;
    } else{
        return (b-a+2)/2;
    }
}

int main(){
    ll l, r, d, u;
    cin >> l >> r >> d >> u;
    ll ans = 0;
    for(ll i=l; i<=r; i++){
        ll x = abs(i);
        if(x%2 == 0){
            ll d1 = max(d, -1*x);
            ll u1 = min(u, x);
            ll val = max(0LL, u1-d1+1);
            ans += val;
        }
        ll a1 = max(x+1, d);
        ll b1 = u;
        ll a2 = d;
        ll b2 = min(-1*x-1, u);
        ans += f(a1, b1);
        ans += f(a2, b2);
    }
    cout << ans << endl;
    return 0;
}