#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(int node, int c, vector<vector<int>>& adj, vector<int>& color){
    color[node] = c;
    for(auto it : adj[node]){
        if(color[it] == -1){
            if(!dfs(it, !c, adj, color)) return false;
        } else{
            if(color[it] == c) return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n+1, -1);
    int flag = 1;
    for(int i=1; i<=n; i++){
        if(color[i] == -1){
            flag = (flag & dfs(i, 0, adj, color));
            if(!flag) break;
        }
    }
    if(!flag){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for(int i=1; i<=n; i++) cout << color[i]+1 << " ";
    cout << endl;
    return 0;
}