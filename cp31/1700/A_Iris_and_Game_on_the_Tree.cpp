#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, string& s, int& q, int& z, int& o){
    vis[node] = 1;
    int leaf = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            leaf = 0;
            dfs(it, adj, vis, s, q, z, o);
        }
    }
    if(leaf){
        if(s[node-1] == '0') z++;
        else if(s[node-1] == '1') o++;
        else q++;
    }
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
        string s;
        cin >> s;
        int totalq = 0;
        for(int i=1; i<n; i++){
            if(s[i] == '?') totalq++;
        }
        vector<int> vis(n+1,0);
        int q, z, o;
        q = z = o = 0;
        dfs(1, adj, vis, s, q, z, o);
        int ans;
        if(s[0] == '0'){
            ans = o + (q+1)/2;
        } else if(s[0] == '1'){
            ans = z + (q+1)/2;
        } else{
            if(o != z){
                ans = max(z, o) + q/2;
            } else{
                int remq = totalq - q;
                if(remq&1){
                    ans = max(z, o) + (q+1)/2;
                } else{
                    ans = max(z, o) + q/2;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}