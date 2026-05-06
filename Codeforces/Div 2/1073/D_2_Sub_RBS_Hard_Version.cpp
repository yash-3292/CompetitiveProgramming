#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll f(int i, int sum, int cnt, int val, int& n, string& s, vector<vector<vector<vector<int>>>>& dp){
    if(sum < 0) return 0;
    if(i == n){
        if(sum != 0) return 0;
        if(cnt == 0) return 0;
        if(val == 3) return cnt-2;
        return 0;
    }
    
    if(dp[i][sum][cnt][val] != -1) return dp[i][sum][cnt][val];

    int sum1 = sum;
    if(s[i] == '(') sum1++;
    else sum1--;
    int val1 = val;
    if(val1 == 0 && s[i] == ')') val1++;
    else if((val1 == 1 || val1 == 2) && s[i] == '(') val1++;
    ll take = f(i+1, sum1, cnt+1, val1, n, s, dp);
    ll notTake = f(i+1, sum, cnt, val, n, s, dp);
    ll ans = (take + notTake)%mod;

    return dp[i][sum][cnt][val] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(4, -1))));
        ll ans = f(0, 0, 0, 0, n, s, dp);
        cout << ans << endl;
    }
    return 0;
}