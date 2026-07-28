#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<ll> preSum(n);
    vector<ll> sufSum(n);
    preSum[0] = (arr[0] > 0) ? arr[0] : 0;
    for(ll i=1; i<n; i++){
        preSum[i] = preSum[i-1];
        if(arr[i] > 0) preSum[i] += arr[i];
    }
    sufSum[n-1] = (arr[n-1] < 0) ? -1*arr[n-1] : 0;
    for(ll i=n-2; i>=0; i--){
        sufSum[i] = sufSum[i+1];
        if(arr[i] < 0) sufSum[i] -= arr[i];
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll val;
        if(i == n-1) val = preSum[i];
        else val = preSum[i] + sufSum[i+1];
        ans = max(ans,val);
    }
    ans = max(ans, sufSum[0]);
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