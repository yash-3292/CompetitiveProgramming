#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<n; i++) cin >> b[i];
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        ll j = 0;
        while(a[i] > b[j] && j < n) j++;
        arr[i] = j;
    }
    ll cnt = 0;
    for(ll i=0; i<n; i++){
        ll j = i;
        while(j < n && arr[j] > i) j++;
        if(j == n){
            cout << -1 << endl;
            return;
        }
        if(i == j) continue;
        cnt += j - i;
        ll val = arr[j];
        for(ll k=j; k>i; k--){
            arr[k] = arr[k-1];
        }
        arr[i] = val;
    }
    // for(auto it : arr) cout << it << " ";
    // cout << endl;
    cout << cnt << endl;
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