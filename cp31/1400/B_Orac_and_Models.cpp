#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, vector<int>& arr, vector<int>& dp){
    if(dp[i-1] != -1) return dp[i-1];
    int n = arr.size();
    int ans = 0;
    for(int j=2; (i*j)<=n; j++){
        if(arr[i*j - 1] > arr[i-1]){
            ans = max(ans, f(i*j, arr, dp));
        }
    }
    return dp[i-1] = ans+1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> dp(n,-1);
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, f(i, arr, dp));
        }
        cout << ans << endl;
    }
    return 0;
}