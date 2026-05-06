#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, int l, int& maxi, vector<vector<int>>& adj, vector<int>& vis, vector<int>& level){
    vis[node] = 1;
    level[l]++;
    int num = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            num++;
            dfs(it, l+1, maxi, adj, vis, level);
        }
    }
    maxi = max(maxi, num);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxi = 0;
        vector<int> level(n, 0);
        vector<int> vis(n+1, 0);
        dfs(1, 0, maxi, adj, vis, level);
        for(int i=0; i<n; i++) maxi = max(maxi, level[i]);
        cout << maxi << endl;
    }
    return 0;
}