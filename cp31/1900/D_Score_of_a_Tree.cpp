#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % mod;
        b >>= 1;
        a = (a*a) % mod;
    }
    return res;
}

ll dfs(int node, vector<vector<int>>& adj, vector<int>& vis, ll& sum){
    vis[node] = 1;
    ll maxh = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            ll h = dfs(it, adj, vis, sum);
            maxh = max(maxh, h+1);
        }
    }
    sum = (sum + maxh) % mod;
    return maxh;
}

void solve(){
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
    ll ans = binpow(2,n-1);
    ll sum = 0;
    dfs(1, adj, vis, sum);
    ans = (ans * sum) % mod;
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}