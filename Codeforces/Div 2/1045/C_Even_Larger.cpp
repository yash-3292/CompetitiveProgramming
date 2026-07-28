#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll ans = 0;
    for(ll i=1; i<n; i+=2){
        if(i == n-1){
            if(arr[i-1] > arr[i]){
                ans += arr[i-1] - arr[i];
                arr[i-1] = arr[i];
            }
        } else{
            ll dif = arr[i-1] + arr[i+1] - arr[i];
            if(dif <= 0) continue;
            ans += dif;
            if(arr[i+1] >= dif){
                arr[i+1] -= dif;
            } else{
                dif -= arr[i+1];
                arr[i+1] = 0;
                arr[i-1] -= dif;
            }
        }
    }
    // for(auto it : arr) cout << it << " ";
    // cout << endl;
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