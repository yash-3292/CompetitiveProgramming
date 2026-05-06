#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastIO() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL); 
}

int main(){
    fastIO();
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<pair<int,int>>> adj1(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj1[v].push_back({u, w});
    }
    vector<ll> dist(n+1, 1e17);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        int node = it.second;
        if(dist[node] < d) continue;
        for(auto it : adj[node]){
            int v = it.first;
            ll w = (ll)it.second;
            if(d+w < dist[v]){
                dist[v] = d+w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i=1; i<=n; i++) pq.push({dist[i], i});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        ll d = it.first;
        int node = it.second;
        if(dist[node] < d) continue;
        for(auto it : adj1[node]){
            int v = it.first;
            ll w = (ll)it.second;
            if(d+w < dist[v]){
                dist[v] = d+w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(dist[i] == 1e17) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}