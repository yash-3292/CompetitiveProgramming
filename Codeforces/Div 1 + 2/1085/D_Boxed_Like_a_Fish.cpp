#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int k){
    vis[node] = 1;
    int mini = 1e9;
    int secmini = 1e9;
    int cntleaf = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            int val = dfs(it, adj, vis, k);
            cntleaf += (val == 1);
            if(val <= mini){
                secmini = mini;
                mini = val;
            } else if(val <= secmini){
                secmini = val;
            }
        }
    }
    if((secmini != 1e9 && mini+secmini <= 2*(k-1)) || (cntleaf > 1) || (cntleaf >= 1 && secmini <= k)) return 1;
    if(mini == 1e9) return 1;
    else return mini+1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, v;
        cin >> n >> k >> v;
        v--;
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n, 0);
        int ans = dfs(v, adj, vis, k);
        if(ans == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}