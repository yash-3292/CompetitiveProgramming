#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll f(int i, int j, vector<string>& arr, vector<vector<ll>>& dp){
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    ll val1 = 0;
    ll val2 = 0;
    if(i > 0 && arr[i-1][j] == '.'){
        val1 = f(i-1, j, arr, dp);
    }
    if(j > 0 && arr[i][j-1] == '.'){
        val2 = f(i, j-1, arr, dp);
    }
    ll ans = (val1+val2)%mod;
    return dp[i][j] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    if(arr[n-1][n-1] == '*'){
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<ll>> dp(n, vector<ll>(n,-1));
    ll ans = f(n-1, n-1, arr, dp);
    cout << ans << "\n";
    return 0;
}