#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) cin >> b[i];
    for(ll i=n-1; i>=1; i--){
        if(a[i] <= b[i]) a[i] = b[i];
        else {
            ll diff = a[i] - b[i];
            a[i] -= diff;
            a[i-1] += diff;
        }
    }
    if(a[0] > b[0]) cout << "NO" << endl;
    else cout << "YES" << endl;
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