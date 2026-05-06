#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int w = 0;
int b = 0;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int flag){
    if(flag == 0) w++;
    else b++;
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it, adj, vis, !flag);
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    dfs(1, adj, vis, 0);
    ll ans = (ll)w * (ll)b;
    ans -= (ll)(n-1);
    cout << ans << endl;
    return 0;
}