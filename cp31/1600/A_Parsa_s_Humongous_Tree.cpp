#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dfs(int node, int prev, int parent, vector<vector<int>>& adj, vector<int>& l, vector<int>& r, vector<vector<ll>>& dp){
    if(dp[node][prev] != -1) return dp[node][prev];
    
    ll val1 = 0;
    if(parent != -1){
        if(prev) val1 = abs(r[parent]-l[node]);
        else val1 = abs(l[parent]-l[node]);
    }
    for(auto it : adj[node]){
        if(it == parent) continue;
        val1 += dfs(it, 0, node, adj, l, r, dp);
    }

    ll val2 = 0;
    if(parent != -1){
        if(prev) val2 = abs(r[parent]-r[node]);
        else val2 = abs(l[parent]-r[node]);
    }
    for(auto it : adj[node]){
        if(it == parent) continue;
        val2 += dfs(it, 1, node, adj, l, r, dp);
    }

    return dp[node][prev] = max(val1, val2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        vector<int> l(n);
        vector<int> r(n);
        for(int i=0; i<n; i++) cin >> l[i] >> r[i];
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        ll ans = dfs(0, 0, -1, adj, l, r, dp);
        cout << ans << endl;
    }
    return 0;
}