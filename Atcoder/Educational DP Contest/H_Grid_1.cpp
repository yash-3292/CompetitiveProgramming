#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll f(int i, int j, vector<string>& arr, vector<vector<ll>>& dp){
    if(i < 0) return 0;
    if(j < 0) return 0;
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = 0;
    if(arr[i][j] == '.'){
        ans = (f(i-1, j, arr, dp) + f(i, j-1, arr, dp))%mod;
    }

    return dp[i][j] = ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    ll ans = f(n-1, m-1, arr, dp);
    cout << ans << endl;
    return 0;
}