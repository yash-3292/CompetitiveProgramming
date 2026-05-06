#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int val, vector<vector<int>>& adj, vector<int>& vis, vector<int>& arr){
    vis[node] = 1;
    arr[node] = val;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, !val, adj, vis, arr);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int flag = 1;
        for(int i=1; i<=n; i++) if(adj[i].size() > 2) flag = 0;
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        vector<int> vis(n+1);
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++) if(!vis[i]) dfs(i, 1, adj, vis, arr);
        for(int i=1; i<=n; i++){
            for(auto j : adj[i]){
                if(arr[i] == arr[j]) flag = 0;
            }
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}