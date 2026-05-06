#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(int i, int j, int m, int n, string& l, string& r, vector<vector<int>>& pos, vector<vector<int>>& dp){
    if(i == m) return false;
    if(j >= n) return true;
    
    if(dp[i][j] != -1) return dp[i][j];

    int a = l[i]-'0';
    int b = r[i]-'0';
    for(int val=a; val<=b; val++){
        auto it = lower_bound(pos[val].begin(), pos[val].end(), j);
        if(it == pos[val].end()) return true;
        int position = *it;
        if(f(i+1, position+1, m, n, l, r, pos, dp)) return true;
    }

    return dp[i][j] = false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int m;
        cin >> m;
        string l, r;
        cin >> l;
        cin >> r;
        int n = s.size();
        vector<vector<int>> pos(10);
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            pos[s[i]-'0'].push_back(i);
        }
        bool flag = f(0, 0, m, n, l, r, pos, dp);
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}