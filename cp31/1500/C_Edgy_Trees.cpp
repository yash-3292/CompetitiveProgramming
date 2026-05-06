#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

ll binpow(ll a, ll b){
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

int dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, vector<int>& arr){
    vis[node] = 1;
    int cnt = 1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            int val = dfs(it.first, adj, vis, arr);
            if(it.second){
                arr.push_back(val);
            } else{
                cnt += val;
            }
        }
    }
    return cnt;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v,x});
        adj[v].push_back({u,x});
    }
    vector<int> vis(n+1, 0);
    vector<int> arr;
    int val = dfs(1, adj, vis, arr);
    arr.push_back(val);
    ll ans = binpow(n, k); 
    for(auto it : arr){
        ll val = binpow((ll)it, (ll)k);
        ans -= val;
        ans = (ans+mod)%mod;
    }
    cout << ans << endl;
    return 0;
}