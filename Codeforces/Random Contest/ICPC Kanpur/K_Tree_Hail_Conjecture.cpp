#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int dfs(int node, int& n, vector<vector<int>>& adj, vector<int>& vis, int& mini){
    vis[node] = 1;
    int total = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            int val = dfs(it, n, adj, vis, mini);
            mini = min(mini, abs(val - (n-val)));
            total += val;
        }
    }
    return total;
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
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        vector<int> vis(n+1, 0);
        int mini = 1e9;
        dfs(1, n, adj, vis, mini);
        cout << mini << endl;
    }
    return 0;
}