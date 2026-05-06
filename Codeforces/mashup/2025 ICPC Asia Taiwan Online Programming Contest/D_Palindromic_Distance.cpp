#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int j, string& s, vector<vector<int>>& dp){
    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int ans;
    if(s[i] == s[j]) ans = f(i+1, j-1, s, dp);
    else{
        ans = min(f(i+1, j, s, dp), f(i, j-1, s, dp));
        ans = min(ans, f(i+1, j-1, s, dp));
        ans++;
    }

    return dp[i][j] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans = f(0, n-1, s, dp);
        cout << ans << endl;
    }
}