#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll i, ll j, vector<ll>& arr, vector<ll>& preSum, vector<vector<ll>>& dp){
    if(i > j){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    ll sum = preSum[j];
    if(i > 0) sum -= preSum[i-1];
    ll val = min(f(i+1, j, arr, preSum, dp), f(i, j-1, arr, preSum, dp));
    ll ans = sum - val;

    return dp[i][j] = ans;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<ll> preSum(n);
    preSum[0] = arr[0];
    for(ll i=1; i<n; i++){
        preSum[i] = preSum[i-1] + arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    ll ans1 = f(0, n-1, arr, preSum, dp);
    ll ans2 = preSum[n-1] - ans1;
    ll ans = ans1 - ans2;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}