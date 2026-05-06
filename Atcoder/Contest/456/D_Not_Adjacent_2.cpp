#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll f(int i, int prev, vector<int>& arr, vector<vector<ll>>& dp){
    if(i == arr.size()) return 1;

    if(dp[i][prev] != -1) return dp[i][prev];

    ll notTake = f(i+1, prev, arr, dp);
    ll take = 0;
    if(arr[i] != prev){
        take = f(i+1, arr[i], arr, dp);
    }
    ll ans = (take + notTake) % mod;
    return dp[i][prev] = ans;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        arr[i] = s[i] - 'a';
    }
    vector<vector<ll>> dp(n, vector<ll>(4, -1));
    ll ans = f(0, 3, arr, dp);
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}