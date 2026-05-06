#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int node, int upper, vector<vector<int>>& adj, vector<int>& vis, vector<int>& arr){
    vis[node] = 1;
    int child = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            child += f(it, upper+1, adj, vis, arr);
        }
    }
    int val = upper - child;
    arr[node-1] = val;
    return child+1;
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
    vector<int> vis(n+1);
    vector<int> arr(n);
    f(1, 0, adj, vis, arr);
    sort(arr.begin(), arr.end(), greater<int>());
    ll ans = 0;
    for(int i=0; i<k; i++){
        ans += (ll)arr[i];
    }
    cout << ans << endl;
    return 0;
}