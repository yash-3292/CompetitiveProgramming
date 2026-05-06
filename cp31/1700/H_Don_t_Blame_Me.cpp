#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll f(int i, int val, int k, vector<int>& arr, vector<vector<ll>>& dp){
    if(i < 0){
        int setbits = __builtin_popcount(val);
        // cout << setbits << " " << k << " " << endl;
        if(setbits == k) return 1;
        else return 0;
    }

    if(dp[i][val] != -1) return dp[i][val];

    ll ans = 0;
    ans = (ans + f(i-1, (val&arr[i]), k, arr, dp))%mod;
    ans = (ans + f(i-1, val, k, arr, dp))%mod;

    return dp[i][val] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<vector<ll>> dp(n, vector<ll>(64, -1));
        ll ans = f(n-1, 63, k, arr, dp);
        if(k == 6) ans--;
        cout << ans << endl;
    }
    return 0;
}