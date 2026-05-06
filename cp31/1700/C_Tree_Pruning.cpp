#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int height(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    int ans = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            int val = height(it, adj, vis);
            ans = max(ans, val);
        }
    }
    return ans+1;
}

int dfs(int node, int level, vector<vector<int>>& adj, vector<int>& vis, vector<int>& up, vector<int>& down){
    vis[node] = 1;
    down[level]++;
    int ans = level;
    for(auto it : adj[node]){
        if(!vis[it]){
            int val = dfs(it, level+1, adj, vis, up, down);
            ans = max(ans, val);
        }
    }
    up[ans]++;
    return ans;
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
        int h = height(1, adj, vis);
        for(int i=0; i<=n; i++) vis[i] = 0;
        vector<int> down(h+1, 0);
        vector<int> up(h+1, 0);
        dfs(1, 1, adj, vis, up, down);
        
        int mini = INT_MAX;
        for(int i=1; i<=h; i++){
            up[i] = up[i]+up[i-1];
        }
        for(int i=h-1; i>=0; i--){
            down[i] = down[i] + down[i+1];
        }

        for(int i=1; i<=h; i++){
            if(i == h){
                mini = min(mini, up[i-1]);
            } else{
                mini = min(mini, up[i-1] + down[i+1]);
            }
        }
        // for(auto it : down) cout << it << " ";
        // cout << endl;
        // for(auto it : up) cout << it << " ";
        // cout << endl;
        cout << mini << endl;
    }
    return 0;
}