#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int chance, vector<int>& arr, vector<pair<int,int>>& dp){
    int n = arr.size();
    if(i >= n) return 0;
    if(chance){
        if(dp[i].first != -1) return dp[i].first;
        int ans = min(f(i+1, !chance, arr, dp), f(i+2, !chance, arr, dp));
        return dp[i].first = ans;
    } else{
        if(dp[i].second != -1) return dp[i].second;
        int ans = arr[i] + f(i+1, !chance, arr, dp);
        if(i != n-1) ans = min(ans, arr[i]+arr[i+1]+f(i+2, !chance, arr, dp));
        return dp[i].second = ans;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<pair<int,int>> dp(n, {-1,-1});
        int ans = f(0, 0, arr, dp);
        cout << ans << endl;
    }
    return 0;
}