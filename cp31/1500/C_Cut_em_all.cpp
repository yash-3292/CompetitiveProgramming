#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int &ans){
    vis[node] = 1;
    int cnt = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            cnt += dfs(it, adj, vis, ans);
        }
    }
    if(cnt%2 == 0){
        ans++;
        return 0;
    } 
    return cnt;
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
    if(n&1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> vis(n+1, 0);
    int ans = 0;
    dfs(1, adj, vis, ans);
    ans--;
    cout << ans << endl;
    return 0;
}