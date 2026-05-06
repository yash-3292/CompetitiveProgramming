#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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

pair<int,int> dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& l, int& r, int& dia){
    vis[node] = 1;
    vector<pair<int,int>> arr;
    arr.push_back({0, node});
    for(auto it : adj[node]){
        if(!vis[it]){
            auto p = dfs(it, adj, vis, l, r, dia);
            p.first++;
            arr.push_back(p);
        }
    }
    sort(arr.begin(), arr.end(), greater<pair<int,int>>());
    if(arr.size() > 1){
        if(arr[0].first + arr[1].first > dia){
            dia = arr[0].first + arr[1].first;
            l = arr[0].second;
            r = arr[1].second;
        }
    }
    return arr[0];
}

void dfs1(int node, int dist, int root, vector<vector<int>>& adj, vector<int>& vis, vector<vector<int>>& arr){
    vis[node] = 1;
    arr.push_back({dist, root, node});
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs1(it, dist+1, root, adj, vis, arr);
        }
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
    int l = 1;
    int r = 1;
    int dia = 0;
    dfs(1, adj, vis, l, r, dia);
    vector<vector<int>> arr;
    for(int i=0; i<=n; i++) vis[i] = 0; 
    dfs1(l, 0, l, adj, vis, arr);
    for(int i=0; i<=n; i++) vis[i] = 0; 
    dfs1(r, 0, r, adj, vis, arr);
    sort(arr.begin(), arr.end());
    // for(auto it : arr){
    //     cout << it[0] << " " << it[1] << " " << it[2] << endl;
    // }
    vector<int> ans(n);
    int component = n;
    DisjointSet dsu(n);
    for(int i=n; i>0; i--){
        while(arr.back()[0] >= i){
            int u = arr.back()[1];
            int v = arr.back()[2];
            if(dsu.findUPar(u) != dsu.findUPar(v)){
                component--;
                dsu.unionByRank(u, v);
            }
            arr.pop_back();
        }
        ans[i-1] = component;
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}