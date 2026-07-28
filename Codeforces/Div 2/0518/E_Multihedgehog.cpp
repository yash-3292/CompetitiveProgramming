#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int x, int& flag){
    vis[node] = 1;
    int cnt = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            cnt++;
            dfs(it, adj, vis, x-1, flag);
        }
    }
    if(cnt == 0){
        if(x != 0){
            flag = 0;
        }
    } else if(cnt < 3){
        flag = 0;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n == 1){
        cout << "No" << endl;
        return;
    }
    queue<int> q;
    int root = -1;
    vector<int> vis(n+1);
    for(int i=1; i<=n; i++){
        if(adj[i].size()==1){
            q.push(i);
            vis[i] = 1;
        }
    }
    while(!q.empty()){
        int node = q.front();
        root = node;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    int flag = 1;
    for(int i=0; i<=n; i++) vis[i] = 0;
    dfs(root, adj, vis, k, flag);
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}