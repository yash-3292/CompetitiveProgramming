#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> prod(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        prod[i] = x-1;
    } 
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans(k, 0);
    queue<pair<int,int>> q;
    vector<int> vis(n, 0);
    q.push({0, 0});
    vis[0] = 1;
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        ans[prod[node]] = max(ans[prod[node]], dist);
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, dist+1});
            }
        }
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}