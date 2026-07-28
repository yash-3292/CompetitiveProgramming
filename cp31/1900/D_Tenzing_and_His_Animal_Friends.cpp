#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(ll node, vector<vector<pair<ll,ll>>>& adj, vector<ll>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            dfs(it.first, adj, vis);
        }
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(ll i=0; i<m; i++){
        ll u, v, y;
        cin >> u >> v >> y;
        adj[u].push_back({v,y});
        adj[v].push_back({u,y});
    }
    vector<ll> vis(n+1,0);
    dfs(1,adj,vis);
    if(!vis[n]){
        cout << "inf" << endl;
        return;
    }
    vector<ll> dist(n+1, 1e16);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    dist[n] = 0;
    pq.push({0,n});
    while(!pq.empty()){
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(dist[node] < dis) continue;
        for(auto it : adj[node]){
            ll v = it.first;
            ll w = it.second;
            if(dis+w < dist[v]){
                dist[v] = dis+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(ll i=1; i<=n; i++) if(dist[i] > dist[1]) dist[i] = dist[1];
    unordered_map<ll,ll> mpp;
    vector<ll> arr;
    for(ll i=1; i<=n; i++) {
        if(dist[i] == 0) continue;
        if(mpp.find(dist[i]) == mpp.end()){
            arr.push_back(dist[i]);
            mpp[dist[i]] = 1;
        }
    }
    sort(arr.begin(), arr.end());
    cout << dist[1] << " " << arr.size() << endl;
    ll sz = arr.size();
    for(ll i=0; i<sz; i++){
        ll val;
        if(i == 0) val = 0;
        else val = arr[i-1];
        for(ll j=1; j<=n; j++){
            if(dist[j] > val) cout << 1;
            else cout << 0;
        } 
        cout << " ";
        if(i == 0) cout << arr[i] << endl;
        else cout << arr[i]-arr[i-1] << endl; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}