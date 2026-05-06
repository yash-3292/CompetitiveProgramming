#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool possible(int node, int parent, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = true;
    int total = 0;
    for(auto it : adj[node]){
        if(it != parent){
            if(!vis[it]){
                
            } else{
                return false;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        while(m--){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> vis(n+1, 0);
        bool flag = true;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(!possible(i, -1, adj, vis)) flag = false;
            }
        }
    }
    return 0;
}