#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> s(n+1);
        for(int i=1; i<=n; i++) cin >> s[i];
        int smax = 0;
        for(int i=1; i<n; i++) smax = max(s[i], smax);
        vector<vector<ll>> dist(smax+1, vector<ll>(n+1, 1e17));
        priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;
        dist[s[1]][1] = 0;
        pq.push({0, {s[1], 1}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ll d = it.first;
            int bike = it.second.first;
            int node = it.second.second;
            if(s[node] < bike && d < dist[s[node]][node]){
                dist[s[node]][node] = d;
                pq.push({dist[s[node]][node], {s[node], node}});
                continue;
            }
            for(auto it : adj[node]){
                int v = it.first;
                ll weight = (ll)it.second * (ll)bike;
                if(d+weight < dist[bike][v]){
                    dist[bike][v] = d+weight;
                    pq.push({dist[bike][v], {bike, v}});
                }
            }
        }
        ll ans = 1e15;
        for(int i=1; i<=smax; i++){
            ans = min(ans, dist[i][n]);
        }
        cout << ans << endl;
    }
    return 0;
}