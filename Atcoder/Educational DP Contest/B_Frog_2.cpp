#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int k, vector<int>& arr, vector<ll>& dp){
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];
    ll ans = (ll)1e15;
    for(int j=1; j<=k; j++){
        if(i-j >= 0){
            ll val = (ll)abs(arr[i]-arr[i-j]) + f(i-j, k, arr, dp); 
            ans = min(ans, val);
        }
    }
    return dp[i] = ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<ll> dp(n, -1); 
    ll ans = f(n-1, k, arr, dp);
    cout << ans << endl;
    return 0;
}