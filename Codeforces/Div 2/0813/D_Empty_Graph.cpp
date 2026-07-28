#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll mid, ll k, vector<ll> arr){
    ll n = arr.size();
    for(ll i=0; i<n; i++){
        if(2*arr[i] < mid){
            if(k == 0){
                return false;
            }
            arr[i] = 1e9;
            k--;
        }
    }
    if(k >= 2) return true;
    if(k == 1){
        ll val = 0;
        for(ll i=0; i<n; i++){
            val = max(val, arr[i]);
        }
        if(val >= mid) return true;
        return false; 
    } 
    ll val = 0;
    for(ll i=1; i<n; i++){
        val = max(val, min(arr[i], arr[i-1]));
    }
    if(val >= mid) return true;
    return false;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll l = 1;
    ll r = 1e9;
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(check(mid, k, arr)){
            ans = mid;
            l = mid+1;
        } else{
            r = mid-1;
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