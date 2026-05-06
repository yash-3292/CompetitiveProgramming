#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, int parent, int prev, vector<vector<int>>& adj, vector<int>& vis, map<pair<int,int>, int>& mpp){
    vis[node] = 1;
    int val = 0;
    int ind = mpp[{node, parent}];
    for(auto it : adj[node]){
        if(!vis[it]){
            val = max(val, dfs(it, node, ind, adj, vis, mpp));
        }
    }
    return ind > prev ? val : val+1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<pair<int,int>, int> mpp;
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1);
        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            mpp[{u,v}] = i;
            mpp[{v,u}] = i;
        }
        int val = 0;
        vis[1] = 1;
        for(auto it : adj[1]){
            val = max(val, dfs(it, 1, -1, adj, vis, mpp));
        }
        cout << val+1 << endl;
    }
    return 0;
}