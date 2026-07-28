#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n), d(n);
    for(ll i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        if(d[i] < b[i]){
            ans += abs(d[i] - b[i]);
            ans += a[i];
        } else{
            if(c[i] < a[i]){
                ans += abs(a[i] - c[i]);
            }
        }
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