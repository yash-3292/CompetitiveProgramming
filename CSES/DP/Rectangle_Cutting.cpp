#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int a, int b, vector<vector<int>>& dp){
    if(a == b) return 0;

    if(dp[a][b] != -1) return dp[a][b];

    int ans = INT_MAX;
    for(int i=1; i<a; i++){
        int val = f(i, b, dp) + f(a-i, b, dp);
        ans = min(ans, val);
    }
    for(int i=1; i<b; i++){
        int val = f(a, i, dp) + f(a, b-i, dp);
        ans = min(ans, val);
    }
    ans++;
    return dp[a][b] = ans;
}

int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
    int ans = f(a, b, dp);
    cout << ans << "\n";
    return 0;
}