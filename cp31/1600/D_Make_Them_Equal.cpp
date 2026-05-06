#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int k, vector<int>& ops, vector<int>& c, vector<vector<int>>& dp){
    if(i < 0) return 0;

    if(dp[i][k] != -1) return dp[i][k];
    int notTake = f(i-1, k, ops, c, dp);
    int take = 0;
    if(k >= ops[i]) take = c[i] + f(i-1, k-ops[i], ops, c, dp);

    return dp[i][k] = max(take, notTake);
}

int main(){
    int sz = 1e3+10;
    vector<int> arr(sz, -1);
    arr[1] = 0;
    for(int i=1; i<sz; i++){
        for(int j=1; j<=i; j++){
            int ind = i+i/j;
            if(ind < sz){
                if(arr[ind] == -1) arr[ind] = arr[i] + 1;
                else arr[ind] = min(arr[ind], arr[i]+1);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        vector<int> ops(n);
        int opSum = 0, coinSum = 0;
        for(int i=0; i<n; i++){
            cin >> b[i];
            ops[i] = arr[b[i]];
            opSum += ops[i];
        } 
        for(int i=0; i<n; i++){
            cin >> c[i];
            coinSum += c[i];
        } 
        if(k >= opSum){
            cout << coinSum << endl;
            continue;
        }
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        int ans = f(n-1, k, ops, c, dp);
        cout << ans << endl;
    }
    return 0;
}