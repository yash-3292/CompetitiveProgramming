#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    reverse(arr.begin(), arr.end());
    vector<ll> preSum(n);
    preSum[0] = arr[0];
    for(ll i=1; i<n; i++) preSum[i] = preSum[i-1] + arr[i];
    // vector<ll> preMin(n);
    // preMin[0] = arr[0];
    // for(ll i=1; i<n; i++) preMin[i] = min(preMin[i-1], arr[i]);
    vector<ll> sufMax(n);
    sufMax[n-1] = arr[n-1];
    for(ll i=n-2; i>=0; i--) sufMax[i] = max(sufMax[i+1], arr[i]);
    for(ll i=1; i<=n; i++){
        if(i == n){
            cout << preSum[i-1] << " ";
            continue;
        }
        ll ans = preSum[i-1];
        if(arr[i-1] < sufMax[i]){
            ans = ans - arr[i-1] + sufMax[i];
        }
        cout << ans << " ";
    }
    cout << endl;
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