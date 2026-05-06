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
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vis(n+1, 0);
    pq.push(1);
    vis[1] = 1;
    while(!pq.empty()){
        int node = pq.top();
        cout << node << " ";
        pq.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                pq.push(it);
                vis[it] = 1;
            }
        }
    }
    cout << endl;
    return 0;
}