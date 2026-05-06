#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool dfs(int node, int c, vector<vector<int>>& adj, vector<int>& color, int &one, int& zero, DisjointSet& ds){
    color[node] = c;
    if(c) one += ds.size[node];
    else zero += ds.size[node];

    for(auto it : adj[node]){
        if(color[it] == -1){
            if(!dfs(it, !c, adj, color, one, zero, ds)) return false;
        } else{
            if(color[node] == color[it]) return false; 
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        DisjointSet ds(n);
        vector<vector<int>> adj(n+1);
        vector<pair<int,int>> edges;
        for(int i=0; i<m; i++){
            int u, v;
            string s;
            cin >> u >> v >> s;
            if(s == "crewmate"){
                ds.unionBySize(u, v);
            } else{
                edges.push_back({u, v});
            }
        }
        for(auto it : edges){
            int pu = ds.findUPar(it.first);
            int pv = ds.findUPar(it.second);
            adj[pu].push_back(pv);
            adj[pv].push_back(pu);
        }
        vector<int> color(n+1, -1);
        int ans = 0;
        int flag = 1;
        for(int i=1; i<=n; i++){
            if(i == ds.findUPar(i) && color[i] == -1){
                int one = 0;
                int zero = 0;
                int f = dfs(i, 0, adj, color, one, zero, ds);
                if(!f){
                    flag = 0;
                    break;
                }
                ans += max(one, zero);
            }
        }
        if(!flag){
            cout << -1 << endl;
        } else{
            cout << ans << endl;
        }
    }
    return 0;
}