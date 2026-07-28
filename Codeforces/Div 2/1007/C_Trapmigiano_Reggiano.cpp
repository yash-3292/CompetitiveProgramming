#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ans);
        }
    }
    ans.push_back(node);
}

void solve(){
    int n, s, e;
    cin >> n >> s >> e;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    vector<int> ans;
    dfs(e, adj, vis, ans);
    for(auto it : ans) cout << it << " ";
    cout << endl;
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