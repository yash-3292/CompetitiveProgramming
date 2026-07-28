#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int state, string& t, vector<vector<int>>& dp){
    if(i == t.size()) return 0;

    if(dp[i][state] != -1) return dp[i][state];

    int ans = 0;
    if(state == 1){
        if(t[i] == '1') ans = 1 + f(i+1, 1, t, dp);
        else ans = f(i+1, 1, t, dp);
    } else{
        if(t[i] == '0') ans = 1 + f(i+1, 0, t, dp);
        else{
            int take = 0;
            int notTake = 0;
            take = 1 + f(i+1, 1, t, dp);
            notTake = f(i+1, 0, t, dp);
            ans = max(take, notTake);
        }
    }

    return dp[i][state] = ans;
}

void solve(){
    string s;
    cin >> s;
    int startSize = s.size();
    string t;
    for(auto ch : s){
        if(ch == '4') continue;
        if(ch == '2') t += '0';
        else t += '1';
    }
    vector<vector<int>> dp(t.size(), vector<int>(2, -1));
    int ans = f(0, 0, t, dp);
    ans = startSize - ans;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}