#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<pair<int,int>>& ans){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            ans.push_back({node, it});
            dfs(it, adj, vis, ans);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = arr[0];
        for(int i=1; i<n; i++) pre[i] = min(pre[i-1], arr[i]);
        suf[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) suf[i] = max(suf[i+1], arr[i]);
        int flag = 1;
        for(int i=1; i<n; i++){
            if(pre[i-1] > suf[i]) flag = 0;
        }
        if(!flag){
            cout << "No" << endl;
            continue;
        }
        if(flag) cout << "Yes" << endl;
        vector<vector<int>> adj(n+1);
        vector<pair<int,int>> edge;
        for(int i=1; i<n; i++){
            if(arr[i-1] != pre[i-1]) edge.push_back({arr[i-1], pre[i-1]});
            if(arr[i] != suf[i]) edge.push_back({arr[i], suf[i]});
            edge.push_back({pre[i-1], suf[i]});
        }
        for(auto it : edge){
            int u = it.first;
            int v = it.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n+1, 0);
        vector<pair<int,int>> ans;
        dfs(1, adj, vis, ans);
        for(auto it : ans) cout << it.first << " " << it.second << endl;
    }
    return 0;
}