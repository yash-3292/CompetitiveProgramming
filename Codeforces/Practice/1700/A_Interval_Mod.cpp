#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll op(ll a, ll p, ll q){
    return (a%p)%q;
}

void solve(){
    ll n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll ans = 0;
    for(ll i=0; i<n; i++) ans += arr[i];
    ll val = 0;
    for(ll i=0; i<n; i++){
        val += min(op(arr[i], p, q), op(arr[i], q, p));
    }
    ll val1 = val;
    ll i = 0;
    ll j = 0;
    while(j < n){
        val1 += op(arr[j], p, q) - min(op(arr[j], p, q), op(arr[j], q, p));
        if(j-i+1 > k){
            val1 -= op(arr[i], p, q) - min(op(arr[i], p, q), op(arr[i], q, p));
            i++;
        }
        if(j-i+1 == k){
            ans = min(ans, val1);
        }
        j++;
    }
    ll val2 = val;
    i = 0;
    j = 0;
    while(j < n){
        val2 += op(arr[j], q, p) - min(op(arr[j], p, q), op(arr[j], q, p));
        if(j-i+1 > k){
            val2 -= op(arr[i], q, p) - min(op(arr[i], p, q), op(arr[i], q, p));
            i++;
        }
        if(j-i+1 == k){
            ans = min(ans, val2);
        }
        j++;
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