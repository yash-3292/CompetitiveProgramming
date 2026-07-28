#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll dfs(ll node, vector<vector<ll>>& adj, vector<ll>& vis, ll& ans){
    vis[node] = 1;
    ll ans1 = 1;
    ll ans2 = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            ll val = dfs(it, adj, vis, ans);
            ans1 = (ans1 * val) % mod;
            ans2 = (ans2 + val) % mod;
        }
    }
    ans = (ans2 + ans) % mod; 
    ans1++;
    return ans1;
}

void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0; i<n-1; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> vis(n+1, 0);
    ll ans = 0;
    ll ans2 = dfs(1, adj, vis, ans);
    ans = (ans + ans2) % mod;
    ans = (ans - n + 1 + mod) % mod;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}