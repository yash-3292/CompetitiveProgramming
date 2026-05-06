#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void clearVis(vector<int>& vis){
    int n = vis.size();
    for(int i=0; i<n; i++) vis[i] = 0;
}

ll dfsp(int node, vector<vector<int>>& adj, vector<int>& vis, vector<ll>& a, vector<ll>& p){
    vis[node] = 1;
    ll ans = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            ans += dfsp(it, adj, vis, a, p);
        }
    }
    p[node] = ans;
    return p[node] + a[node];
}

void dfss(int node, vector<vector<int>>& adj, vector<int>& vis, vector<ll>& p, vector<ll>& subTCost){
    vis[node] = 1;
    ll ans = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfss(it, adj, vis, p, subTCost);
            ans += subTCost[it];
        }
    }
    ans += p[node];
    subTCost[node] = ans;
}

ll dfse(int node, vector<vector<int>>& adj, vector<int>& vis, vector<ll>& a, vector<ll>& p, vector<ll>& extra){
    vis[node] = 1;
    vector<ll> level;
    vector<ll> arr;
    ll maxL = 0; 
    for(auto it : adj[node]){
        if(!vis[it]){
            ll l = dfse(it, adj, vis, a, p, extra);
            extra[node] = max(extra[it], extra[node]);
            maxL = max(maxL, l);
            level.push_back(l);
            arr.push_back(p[it] + a[it]);
        }
    }
    int n = level.size();
    if(n <= 1) return maxL+1;
    vector<ll> preLevel(n), sufLevel(n);
    preLevel[0] = 0;
    for(int i=1; i<n; i++) preLevel[i] = max(preLevel[i-1], level[i-1]);
    sufLevel[n-1] = 0;
    for(int i=n-2; i>=0; i--) sufLevel[i] = max(sufLevel[i+1], level[i+1]);
    for(int i=0; i<n; i++) level[i] = max(preLevel[i], sufLevel[i]);
    for(int i=0; i<n; i++){
        extra[node] = max(extra[node], level[i]*arr[i]);
    }
    return maxL + 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for(int i=1; i<=n; i++) cin >> a[i];
        vector<vector<int>> adj(n+1);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll> p(n+1, 0);
        vector<ll> subTCost(n+1, 0);
        vector<ll> extra(n+1, 0);
        vector<int> vis(n+1, 0);
        dfsp(1, adj, vis, a, p);
        clearVis(vis);
        dfss(1, adj, vis, p, subTCost);
        clearVis(vis);
        dfse(1, adj, vis, a, p, extra);
        for(int i=1; i<=n; i++){
            ll ans = subTCost[i] + extra[i];
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}