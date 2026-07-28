#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, y;
    cin >> n >> y; 
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll ans = LLONG_MIN;
    vector<ll> freq(2e5+10,0);
    for(ll i=0; i<n; i++){
        freq[arr[i]]++;
    }
    for(ll i=1; i<=2e5; i++) freq[i] += freq[i-1];
    for(ll mul=2; mul<=2e5; mul++){
        ll sum = -1*n*y;
        for(ll val=1; (val-1)*mul<2e5; val++){
            ll l = (val-1)*mul;
            ll r = min(val*mul, (ll)2e5);
            ll cnt = freq[r]-freq[l];
            sum += min(freq[val]-freq[val-1], cnt)*y;
            sum += cnt*val;
        }
        ans = max(ans, sum);
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