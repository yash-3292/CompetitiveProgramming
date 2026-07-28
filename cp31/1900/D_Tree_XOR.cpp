#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& arr, vector<int>& cnt, ll& val){
    vis[node] = 1;
    int ans = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            ll ans1 =  dfs(it, adj, vis, arr, cnt, val);
            ans += ans1;
            val += (ll)ans1 * (ll)(arr[node]^arr[it]); 
        }
    }
    cnt[node] = ans;
    return ans;
}

void dfs1(int node, ll val, vector<vector<int>>& adj, vector<int>& vis, vector<int>& arr, vector<int>& cnt, vector<ll>& ans){
    int n = adj.size();
    vis[node] = 1;
    ans[node] = val;
    for(auto it : adj[node]){
        if(!vis[it]){
            ll x;
            ll xorr = arr[it]^arr[node];
            x = val + (ll)(n-2*cnt[it]) * xorr;
            dfs1(it, x, adj, vis, arr, cnt, ans);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    vector<int> cnt(n);
    ll val = 0;
    dfs(0, adj, vis, arr, cnt, val);
    vector<ll> ans(n);
    for(int i=0; i<n; i++) vis[i] = 0;
    dfs1(0, val, adj, vis, arr, cnt, ans);
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}