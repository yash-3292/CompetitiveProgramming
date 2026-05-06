#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(n+1, -1);
    vector<int> vis(n+1, 0);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }
    if(!vis[n]){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> ans;
    int i = n;
    while(i != 1){
        ans.push_back(i);
        i = parent[i];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}