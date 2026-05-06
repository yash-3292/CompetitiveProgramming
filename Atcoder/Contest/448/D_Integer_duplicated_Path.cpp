#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& arr, vector<int>& ans, unordered_map<int,int>& mpp){
    vis[node] = 1;
    if(mpp.find(arr[node]) != mpp.end()) return;
    ans[node] = 0;
    mpp[arr[node]] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, arr, ans, mpp);
        }
    }
    mpp.erase(arr[node]);
}

int main(){
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
    unordered_map<int,int> mpp;
    vector<int> ans(n, 1);
    vector<int> vis(n, 0);
    dfs(0, adj, vis, arr, ans, mpp);
    for(int i=0; i<n; i++){
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}