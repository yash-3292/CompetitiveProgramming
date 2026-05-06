#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int l, int r, vector<int>& arr, vector<vector<ll>>& dp){
    int n = arr.size();
    ll ans = arr[r] - arr[l];
    if(r-l+1 == n) return ans;

    if(dp[l][r] != -1) return dp[l][r];

    ll mini = 1e17;
    if(l > 0){
        mini = min(mini, f(l-1, r, arr, dp));
    }
    if(r < n-1){
        mini = min(mini, f(l, r+1, arr, dp));
    }
    ans += mini;

    return dp[l][r] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll mini = 1e18;
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    for(int i=0; i<n; i++){
        ll ans = f(i, i, arr, dp);
        mini = min(mini, ans);
    }
    cout << mini << endl; 
    return 0;
}