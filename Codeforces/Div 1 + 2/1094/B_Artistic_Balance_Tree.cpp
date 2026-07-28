#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    // ll sum = 0;
    // for(ll i=0; i<n; i++) sum += arr[i];
    vector<ll> e, o;
    bool ef = false, of = false;
    for(ll i=0; i<n; i++){
        if(i&1){
            o.push_back(arr[i]);
        } else{
            e.push_back(arr[i]);
        }
    }
    sort(e.begin(), e.end());
    sort(o.begin(), o.end());
    for(ll i=0; i<m; i++){
        ll x;
        cin >> x;
        x--;
        if(x&1){
            if(o.empty()) continue;
            if(o.back() >= 0){
                o.pop_back();
                of = true;
            } else{
                if(of) continue;
                o.pop_back();
                of = true;
            }
        } else{
            if(e.empty()) continue;
            if(e.back() >= 0){
                e.pop_back();
                ef = true;
            } else{
                if(ef) continue;
                e.pop_back();
                ef = true;
            }
        }
    }
    ll ans = 0;
    for(auto it : o) ans += it;
    for(auto it : e) ans += it;
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