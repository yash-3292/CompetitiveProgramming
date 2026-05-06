#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, int val, vector<vector<int>>& adj, vector<int>& vis, int& one, int& zero, int& flag){
    vis[node] = val;
    if(val) one++;
    else zero++;
    for(auto it : adj[node]){
        if(vis[it] == -1){
            dfs(it, !val, adj, vis, one, zero, flag);
        } else if(vis[it] == val){
            flag = 0;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,-1);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                int one = 0;
                int zero = 0;
                int flag = 1;
                dfs(i, 0, adj, vis, one, zero, flag);
                if(flag) ans += max(one, zero);
            }
        }
        cout << ans << endl;
    }
    return 0;
}