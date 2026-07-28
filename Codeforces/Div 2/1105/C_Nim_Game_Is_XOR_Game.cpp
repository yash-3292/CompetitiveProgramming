#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    vector<ll> preXor(n), sufXor(n);
    preXor[0] = arr[0];
    for(ll i=1; i<n; i++) preXor[i] = preXor[i-1] ^ arr[i];
    sufXor[n-1] = arr[n-1];
    for(ll i=n-2; i>=0; i--) sufXor[i] = sufXor[i+1] ^ arr[i];
    ll ans = 0;
    if(preXor[n-1] == 0){
        ans++;
    }
    for(ll i=0; i<n; i++){
        ll x = 0;
        if(i > 0) x = x ^ preXor[i-1];
        if(i < n-1) x = x ^ sufXor[i+1];
        if(x < arr[i]){
            ans++;
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