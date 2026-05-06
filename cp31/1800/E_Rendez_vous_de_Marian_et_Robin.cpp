#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int src, int n, vector<int>& horses, vector<vector<pair<int,int>>>& adj, vector<ll>& ans){
    vector<ll> dist(n+1, 1e17);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        int node = it.second;
        for(auto it : adj[node]){
            int v = it.first;
            ll weight = it.second;
            if(weight+d < dist[v]){
                dist[v] = weight+d;
                pq.push({dist[v], v});
            }
        }
    }
    vector<ll> disth(n+1, 1e17);
    for(auto it : horses){
        disth[it] = dist[it];
        pq.push({disth[it], it});
    }
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        int node = it.second;
        for(auto it : adj[node]){
            int v = it.first;
            ll weight = it.second/2;
            if(weight+d < disth[v]){
                disth[v] = weight+d;
                pq.push({disth[v], v});
            }
        }
    }
    for(int i=1; i<=n; i++){
        dist[i] = min(dist[i], disth[i]);
    }
    ans = dist;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> horses(h);
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<h; i++) cin >> horses[i];
        for(int i=0; i<m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<ll> dist1;
        f(1, n, horses, adj, dist1);
        vector<ll> dist2;
        f(n, n, horses, adj, dist2);
        ll mini = 1e17;
        for(int i=1; i<=n; i++){
            mini = min(mini, max(dist1[i],dist2[i]));
        }
        if(mini == 1e17) mini = -1;
        cout << mini << endl;
    }
    return 0;
}