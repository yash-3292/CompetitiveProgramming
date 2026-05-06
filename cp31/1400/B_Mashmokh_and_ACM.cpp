#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = (ll)(1e9+7);

ll f(int i, int num, int n, vector<vector<int>>& dp){
    if(i < 0) return 1;

    if(dp[i][num] != -1) return dp[i][num];
    ll ans = 0;
    for(int j=1; j*num<=n; j++){
        ll val = f(i-1, j*num, n, dp);
        ans = (ans+val)%mod;
    }
    return dp[i][num] = ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(k, vector<int>(n+1, -1));
    ll ans = f(k-1, 1, n, dp);
    cout << ans << endl;
    return 0;
}