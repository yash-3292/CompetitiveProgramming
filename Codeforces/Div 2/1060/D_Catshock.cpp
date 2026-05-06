#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, int parent, int n, vector<vector<int>>& adj, vector<pair<int,int>>& ans){
    if(node == n) return 0;
    int real = -1;
    int path = -1;
    for(auto it : adj[node]){
        if(it != parent){
            int val = dfs(it, node, n, adj, ans);
            if(val != -1){
                real = it;
                path = val;
            }
        }
    }
    if(real != -1){
        for(auto it : adj[node]){
            if(it != parent && it != real){
                ans.push_back({2,it});
            }
        }
    }
    if(path == -1) return -1;
    return path+1;
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
        vector<pair<int,int>> ans;
        int path = dfs(1, -1, n, adj, ans);
        cout << path+ans.size() << endl;
        for(auto it : ans) cout << it.first << " " << it.second << endl;
        for(int i=0; i<path; i++) cout << 1 << endl;
        cout << endl;
    }
    return 0;
}