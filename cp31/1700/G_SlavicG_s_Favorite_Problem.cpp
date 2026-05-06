#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, int& val, int& b, vector<vector<pair<int,int>>>& adj, vector<int>& v1, vector<int>& vis){
    vis[node] = 1;
    v1.push_back(val);
    for(auto it : adj[node]){
        if(vis[it.first] || it.first == b) continue;
        val = (val^it.second);
        dfs(it.first, val, b, adj, v1, vis);
        val = (val^it.second);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<n-1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> v1;
        vector<int> v2;
        vector<int> vis(n+1, 0);
        int val = 0;
        dfs(a, val, b, adj, v1, vis);
        for(int i=0; i<=n; i++) vis[i] = 0;
        vis[b] = 1;
        for(auto it : adj[b]){
            val = (val^it.second);
            dfs(it.first, val, b, adj, v2, vis);
            val = (val^it.second);
        }
        map<int,int> mpp;
        int flag = 0;
        for(auto it : v1){
            mpp[it] = 1;
        }
        for(auto it : v2){
            if(mpp.find(it) != mpp.end()){
                flag = 1;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}