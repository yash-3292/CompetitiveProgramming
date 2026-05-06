#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double f(int i, int h, int n, vector<double>& arr, vector<vector<double>>& dp){
    if(i < 0){
        if(h > n/2) return 1;
        else return 0;
    }

    if(dp[i][h] != -1) return dp[i][h];

    double ans = arr[i] * f(i-1, h+1, n, arr, dp) + (1-arr[i]) * f(i-1, h, n, arr, dp);

    return dp[i][h] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<double> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<double>> dp(n, vector<double>(n+1, -1));
    double ans = f(n-1, 0, n, arr, dp);
    cout << setprecision(15) << ans << endl;
    return 0;
}