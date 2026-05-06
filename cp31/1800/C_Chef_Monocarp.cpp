#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int x, int n, vector<int>& arr, vector<vector<int>>& dp){
    if(i == n) return 0; 
    if(x > 2*n) return 1e9;
    
    if(dp[i][x] != -1) return dp[i][x];
    
    int notTake = f(i, x+1, n, arr, dp);
    int take = abs(arr[i]-x) + f(i+1, x+1, n, arr, dp);

    return dp[i][x] = min(take, notTake);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n, vector<int>(2*n+1, -1));
        int ans = f(0, 1, n, arr, dp);
        cout << ans << endl;
    }
    return 0;
}