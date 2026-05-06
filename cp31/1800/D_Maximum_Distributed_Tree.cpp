#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll dfs(int node, int& n, vector<vector<int>>& adj, vector<int>& vis, vector<ll>& arr1){
    vis[node] = 1; 
    ll total = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            ll val = dfs(it, n, adj, vis, arr1);
            total += val;
            arr1.push_back(val * (n-val));
        }
    }
    return total;
}

int main(){
    int t;
    cin >> t;
    while(t--){
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
        int m;
        cin >> m;
        vector<int> temp(m);
        for(int i=0; i<m; i++) cin >> temp[i];
        sort(temp.begin(), temp.end());
        vector<ll> arr;
        for(int i=0; i<n-1-m; i++) arr.push_back(1);
        for(auto x : temp){
            if(arr.size() == n-1){
                arr.back() = (arr.back() * (ll)x)%mod;
            } else{
                arr.push_back(x);
            }
        }
        vector<ll> arr1;
        dfs(1, n, adj, vis, arr1);
        sort(arr1.begin(), arr1.end());
        ll ans = 0;
        for(int i=0; i<n-1; i++){
            ans += (arr1[i]%mod) * (arr[i]%mod);
            ans = ans%mod;
        }
        cout << ans << endl;
    }
    return 0;
}