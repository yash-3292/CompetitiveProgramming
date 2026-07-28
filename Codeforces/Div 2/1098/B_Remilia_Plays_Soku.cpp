#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if(n == 2 || n == 3){
        cout << 1 << endl;
        return;
    }
    ll l = min(x1, x2);
    ll r = max(x1, x2);
    ll d1 = r-l;
    ll d2 = n-r+l;
    ll ans = min(d1, d2) + k;
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