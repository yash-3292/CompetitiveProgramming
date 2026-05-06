#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& mini, int& maxi){
    vis[node] = 1;
    int cnt = 0;
    int len = -1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(adj[it].size() == 1) cnt++;
            int val = dfs(it, adj, vis, mini, maxi);
            if(len == -1) len = val;
            else if(len != val){
                mini = 3;
            }
        }
    }
    maxi -= max(0, (cnt-1));
    return (len == -1) ? 1 : (len+1)%2;
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
    int mini = 1;
    int maxi = n-1;
    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(adj[i].size() > 1){
            dfs(i, adj, vis, mini, maxi);
        }
    }
    cout << mini << " " << maxi << endl;
    return 0;
}