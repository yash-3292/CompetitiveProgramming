#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, vector<vector<int>>& adj, vector<int>& dp){
    if(dp[node] != -1) return dp[node];
    int ans = 1;
    for(auto it : adj[node]){
        int val = 1 + dfs(it, adj, dp);
        ans = max(ans, val);
    }
    return dp[node] = ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> dp(n+1, -1);
    int ans = 0;
    for(int i=1; i<=n; i++){
        int val = dfs(i, adj, dp);
        ans = max(ans, val);
    }
    ans--;
    cout << ans << endl;
    return 0;
}