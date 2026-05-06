#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int x, vector<int>& c, vector<vector<int>>& dp){
    if(i == 0){
        if(x == 0) return 0;
        else if(x%c[i] != 0){
            return 1e9;
        } 
        else return x/c[i];
    }
    
    if(dp[i][x] != -1) return dp[i][x];

    int ans = f(i-1, x, c, dp);
    if(x >= c[i]) ans = min(ans, 1+f(i, x-c[i], c, dp));

    return dp[i][x] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    vector<vector<int>> dp(n, vector<int>(x+1,-1)); 
    int ans = f(n-1, x, c, dp);
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}