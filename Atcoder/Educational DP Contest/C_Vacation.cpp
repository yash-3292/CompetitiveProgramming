#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int prev, vector<vector<int>>& arr, vector<vector<int>>& dp){
    if(i == 0){
        int ans = 0;
        for(int j=0; j<3; j++) ans = max(ans, arr[i][j]);
        return ans;
    }

    if(dp[i][prev] != -1) return dp[i][prev];
    int ans = 0;
    for(int j=0; j<3; j++){
        if(j != prev){
            int val = arr[i][j] + f(i-1, j, arr, dp);
            ans = max(ans, val);
        }
    }

    return dp[i][prev] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(4,-1));
    int ans = f(n-1, 3, arr, dp);
    cout << ans << endl;
    return 0;
}