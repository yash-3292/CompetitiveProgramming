#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, vector<int>& arr, vector<int>& dp){
    if(i == 0) return 0;
    if(i == 1) return abs(arr[0]-arr[1]);

    if(dp[i] != -1) return dp[i];
    int val1 = abs(arr[i]-arr[i-1]) + f(i-1, arr, dp);
    int val2 = abs(arr[i]-arr[i-2]) + f(i-2, arr, dp);

    return dp[i] = min(val1, val2);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> dp(n, -1);
    int ans = f(n-1, arr, dp);
    cout << ans << endl;
    return 0;
}