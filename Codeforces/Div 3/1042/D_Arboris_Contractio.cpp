#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, int parent, vector<vector<int>>& adj, int &cnt){
    if(adj[node].size() == 1){
        cnt++;
        return;
    }
    int total = 0;
    for(auto it : adj[node]){
        if(it != parent){
            dfs(it, node, adj, cnt);
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
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n == 2){
            cout << 0 << endl;
            continue;
        }
        int root;
        for(int i=1; i<=n; i++){
            if(adj[i].size() != 1){
                root = i;
                break;
            }
        }
        int cnt = 0;
        dfs(root,-1,adj,cnt);
        int maxi = 0;
        for(int i=1; i<=n; i++){
            int leaves = 0;
            for(auto it : adj[i]){
                if(adj[it].size() == 1){
                    leaves++;
                } 
            }
            maxi = max(maxi, leaves);
        }
        cnt -= maxi;
        cout << cnt << endl;
    }
    return 0;
}