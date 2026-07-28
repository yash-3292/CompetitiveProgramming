#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int timer = 0;

void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, map<pair<int,int>,int>& bridges){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(vis[it] == 0){
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node]){
                bridges[{it, node}] = 1;
                bridges[{node, it}] = 1;
            }
        } else{
            low[node] = min(low[node], low[it]);
        }
    }
}

int f(int node, int par, int n, vector<vector<int>>& adj, vector<int>& isCycle, vector<pair<int,int>>& ans){
    vector<int> parent(n+1,-1);
    queue<int> q;
    parent[node] = par;
    q.push(node);
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        if(nod == par) break;
        for(auto it : adj[nod]){
            if(parent[nod] == it) continue;
            if(parent[it] != -1) continue;
            if(!isCycle[it]) continue;
            parent[it] = nod;
            q.push(it);
        }
    }
    if(parent[par] == -1) return parent[par];
    int i = par;
    do{
        ans.push_back({i, parent[i]});
        i = parent[i];
    }while(i != par);
    return parent[par];
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> isCycle(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    map<pair<int,int>, int> bridges;
    vector<int> tin(n+1);
    vector<int> low(n+1);
    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i, -1, vis, adj, tin, low, bridges);
    }
    for(int i=1; i<=n; i++){
        for(auto it : adj[i]){
            if(bridges.find({i, it}) == bridges.end()){
                isCycle[i] = 1;
                break;
            }
        }
    }
    // for(auto it : isCycle) cout << it << " ";
    // cout << endl;
    int v = -1;
    for(int i=1; i<=n; i++){
        if(isCycle[i] && adj[i].size() >= 4){
            v = i;
            break;
        }
    }   
    if(v == -1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<pair<int,int>> ans;
    int u1 = -1;
    int u2 = -1;
    for(auto it : adj[v]){
        if(isCycle[it]){
            int x = f(it, v, n, adj, isCycle, ans);
            if(x != -1){
                u1 = it;
                u2 = x;
                break;
            }
        }
    }
    int cnt = 2;
    for(auto it : adj[v]){
        if(it == u1 || it == u2) continue;
        ans.push_back({v,it});
        cnt--;
        if(cnt == 0) break;
    }
    cout << ans.size() << endl;
    for(auto it : ans) cout << it.first << " " << it.second << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}