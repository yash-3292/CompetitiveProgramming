#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, vector<int>& arr, vector<ll>& dp){
    if(i < 0) return 0;

    if(dp[i] != -1) return dp[i];
    ll val1 = (ll)arr[i] + f(i-1, arr, dp);
    ll val2 = 1e18;
    if(i > 0) val2 = (ll)abs(arr[i]-arr[i-1]) + f(i-3, arr, dp);
    if(i-2 >= 0) val2 += (ll)arr[i-2];
    return dp[i] = min(val1, val2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<ll> dp(n, -1);
        ll ans = f(n-1, arr, dp);
        cout << ans << endl;
    }
    return 0;
}