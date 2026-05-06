#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, vector<vector<int>>& adj, int& val, int mid){
    int depth = 0;
    for(auto it : adj[node]){
        int d = dfs(it, adj, val, mid);
        if(d+1 == mid){
            if(node == 1) continue;
            val++;
            continue;
        }
        depth = max(depth, d+1);
    }
    return depth;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        for(int v=2; v<=n; v++){
            int u;
            cin >> u;
            adj[u].push_back(v);
        }
        int l = 1;
        int r = n;
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int val = 0;
            dfs(1, adj, val, mid);
            if(val <= k){
                ans = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}