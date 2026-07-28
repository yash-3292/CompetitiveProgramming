#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& arr, vector<int>& freq, map<int,int>& mpp, vector<int>& next, int& ans, int& maxi){
    vis[node] = 1;
    mpp[arr[node]]++;
    int initial = mpp[next[arr[node]]];
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, arr, freq, mpp, next, ans, maxi);
        }
    }
    int final = mpp[next[arr[node]]];
    if(final - initial < freq[next[arr[node]]]){
        if(arr[node] > maxi){
            maxi = arr[node];
            ans = node;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin >> arr[i];
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1, 0);
    int ans = -1;
    int maxi = -1;
    map<int,int> mpp;
    vector<int> freq(n+10, 0);
    vector<int> next(n+10, 0);
    for(int i=1; i<=n; i++){
        freq[arr[i]]++;
    }
    int el = n+1;
    for(int i=n; i>=0; i--){
        next[i] = el;
        if(freq[i] > 0) el = i; 
    }
    dfs(1, adj, vis, arr, freq, mpp, next, ans, maxi);
    if(ans == -1) cout << 0 << endl;
    else cout << ans << endl;
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