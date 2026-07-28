#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) cin >> b[i];
    ll sum = 0;
    ll ans = 0;
    for(ll i=0; i<n; i++){
        sum += max(a[i], b[i]);
    }
    for(ll i=0; i<n; i++){
        ll val = sum + min(a[i], b[i]);
        ans = max(ans, val);
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