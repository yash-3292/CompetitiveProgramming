#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& cnt){
    cnt++;
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, cnt);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1), d(n+1);
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=1; i<=n; i++) cin >> d[i];
    vector<vector<int>> adj(n+1);
    for(int i=1; i<=n; i++){
        adj[p[i]].push_back(i);
    }
    int cnt = 0;
    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        int val = d[i];
        if(!vis[val]){
            dfs(val, adj, vis, cnt);
        }
        cout << cnt << " ";
    }
    cout << endl;
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