#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int n, vector<int>& arr, vector<int>& dp){
    if(i == n) return 0;
    if(i > n) return 1e8;

    if(dp[i] != -1) return dp[i];
    int notTake = 1 + f(i+1, n, arr, dp);
    int take = f(i+1+arr[i], n, arr, dp);

    return dp[i] = min(notTake, take);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> dp(n, -1);
        int ans = f(0, n, arr, dp);
        cout << ans << endl;
    }
    return 0;
}