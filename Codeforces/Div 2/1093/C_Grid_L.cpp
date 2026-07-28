#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll p, q;
    cin >> p >> q;
    ll x = p + 2*q;
    for(ll n=1; n*n<=x; n++){
        if(x <= n) continue;
        if((x-n)%(2*n+1) != 0) continue;
        ll m = (x-n) / (2*n+1);
        if(p >= abs(n-m)){
            cout << n << " " << m << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}