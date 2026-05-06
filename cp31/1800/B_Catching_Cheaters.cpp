#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int j, string& s, string& t, int& ans, vector<vector<int>>& dp){
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int val = 0;
    if(s[i] == t[j]){
        int x = f(i-1, j-1, s, t, ans, dp);
        val = 2 + max(0, x);
    }
    int x1 = f(i-1, j, s, t, ans, dp);
    int x2 = f(i, j-1, s, t, ans, dp);
    val = max(val, -1 + max(0, max(x1, x2)));
    ans = max(ans, val);

    return dp[i][j] = val;
}

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    f(n-1, m-1, s, t, ans, dp);
    cout << ans << endl;
    return 0;
}