#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

void dfs(int node, int l, vector<vector<int>>& adj, vector<ll>& arr){
    if(arr.size() <= l) arr.push_back(1);
    else arr[l]++;
    for(auto it : adj[node]){
        dfs(it, l+1, adj, arr);
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i=2; i<=n; i++){
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    vector<ll> arr;
    dfs(1, 0, adj, arr);
    int sz = arr.size();
    for(ll i=sz-2; i>=1; i--){
        ll val = ((arr[i] - 1) * arr[i+1]) % mod;
        val = (val + arr[i]) % mod;
        arr[i] = val; 
    }
    ll ans = (arr[1] + 1) % mod;
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