#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int timer;

ll dfs(int node, int par, int n, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<int>& vis, ll &maxi){
    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;
    ll cnt = 1;
    for(auto it : adj[node]){
        if(it == par) continue;
        if(!vis[it]){
            ll val = dfs(it, node, n, adj, tin, low, vis, maxi);
            cnt += val;
            low[node] = min(low[node], low[it]);
            if(tin[node] < low[it]){
                ll ans = (ll)val * (ll)(n-val);
                maxi = max(maxi, ans);
            }
        } else{
            low[node] = min(low[node], low[it]);
        }
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n+1);
        vector<int> low(n+1);
        vector<int> vis(n+1, 0);
        timer = 0;
        ll ans = ((ll)n * (ll)(n-1))/2;
        ll maxi = 0;
        dfs(1, -1, n, adj, tin, low, vis, maxi);
        ans -= maxi;
        cout << ans << endl;
    }
    return 0;
}