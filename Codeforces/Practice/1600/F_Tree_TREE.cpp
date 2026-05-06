#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, int n, int k, vector<vector<int>>& adj, vector<int>& vis, ll& ans){
    vis[node] = 1;
    int total = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            int val = dfs(it, n, k, adj, vis, ans);
            if(val <= n-k) ans += (ll)val;
            total += val;
        }
    }
    total++;
    int rem = n - total;
    if(rem <= n-k) ans += (ll)rem;
    return total;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1);
        ll ans = n;
        dfs(1, n, k, adj, vis, ans);
        cout << ans << endl;
    }
    return 0;
}