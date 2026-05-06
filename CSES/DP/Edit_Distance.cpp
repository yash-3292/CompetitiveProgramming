#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int j, string& a, string& b, vector<vector<int>>& dp){
    if(i == -1) return j+1;
    if(j == -1) return i+1;

    if(dp[i][j] != -1) return dp[i][j];

    int ans;
    if(a[i] == b[j]){
        ans = f(i-1, j-1, a, b, dp);
    } else {
        ans = f(i-1, j, a, b, dp);
        ans = min(ans, f(i, j-1, a, b, dp));
        ans = min(ans, f(i-1, j-1, a, b, dp));
        ans++;
    }

    return dp[i][j] = ans;
}

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = f(n-1, m-1, a, b, dp);
    cout << ans << "\n";
    return 0;
}