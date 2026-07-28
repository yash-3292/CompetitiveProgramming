#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll f(int i, int maxi, int limit, vector<int>& arr, vector<vector<vector<ll>>>& dp){
    if(i == arr.size()) return 1;

    if(dp[i][maxi][limit] != -1) return dp[i][maxi][limit]; 

    ll notTake = f(i+1, maxi, limit, arr, dp);
    ll take = 0;
    if(arr[i] >= limit){
        int nlimit = limit;
        if(arr[i] < maxi) nlimit = arr[i];
        int nmaxi = max(maxi, arr[i]);
        take = f(i+1, nmaxi, nlimit, arr, dp);
    }
    ll ans = (take + notTake) % mod;
    return dp[i][maxi][limit] = ans;
}


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n+1, vector<ll>(n+1, -1)));
    ll ans = f(0, 0, 0, arr, dp);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}