#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(ll node, vector<vector<ll>>& adj, vector<ll>& vis, ll& maxval, ll& cnt){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            ll val = 1 + (adj[node].size() - 1) + (adj[it].size() - 1);
            if(maxval == val) cnt--;
            dfs(it, adj, vis, maxval, cnt);
        }
    }
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
    map<ll,ll> mpp;
    for(ll i=1; i<=n; i++){
        mpp[adj[i].size()]++;
    }
    vector<pair<ll,ll>> arr;
    for(auto it : mpp){
        arr.push_back({it.first, it.second});
    }
    ll maxval;
    ll cnt; 
    if(arr.back().second == 1){
        maxval = 1 + (arr[arr.size()-1].first - 1) + (arr[arr.size()-2].first - 1);
        cnt = arr[arr.size()-2].second;
    } else{
        maxval = 1 + 2*(arr[arr.size()-1].first - 1);
        cnt = ((arr[arr.size()-1].second) * (arr[arr.size()-1].second - 1))/2;
    }
    vector<ll> vis(n+1, 0);
    dfs(1, adj, vis, maxval, cnt);
    ll ans;
    if(cnt == 0) ans = maxval-1;
    else ans = maxval;
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