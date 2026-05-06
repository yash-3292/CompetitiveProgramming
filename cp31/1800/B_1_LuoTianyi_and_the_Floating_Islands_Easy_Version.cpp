#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    a = (a%mod);
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % mod;
        b >>= 1;
        a = (a*a)%mod;
    }
    return res;
}

ll inv(ll a){
    return binpow(a, mod-2);
}

pair<ll,ll> dfs(int node, vector<vector<int>>& adj, vector<int>& vis, ll& ans){
    vis[node] = 1;
    ll totalNum = 0;
    ll totalDist = 0;
    vector<ll> num;
    vector<ll> dist;
    for(auto it : adj[node]){
        if(!vis[it]){
            auto p = dfs(it, adj, vis, ans);
            ll n = p.first;
            ll d = p.second;
            totalNum += n;
            totalDist += d;
            num.push_back(n);
            dist.push_back(d);
        }
    }
    ll n = num.size();
    for(int i=0; i<n; i++){
        ans = (ans + dist[i] * (totalNum - num[i] + 1))%mod;
    }
    totalNum++;
    // totalDist++;
    totalDist = (totalDist + totalNum)%mod;
    return {totalNum, totalDist};
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(k == 1 || k == 3){
        cout << 1 << endl;
        return 0;
    }
    vector<int> vis(n+1, 0);
    ll ans = 0;
    dfs(1, adj, vis, ans);
    ans = ans%mod;
    ll den = ((ll)n*(ll)(n-1))/2;
    ans = ans + den;
    ans = ans%mod;
    den = inv(den);
    ans = (ans * den)%mod;
    cout << ans << endl;
    return 0;
}