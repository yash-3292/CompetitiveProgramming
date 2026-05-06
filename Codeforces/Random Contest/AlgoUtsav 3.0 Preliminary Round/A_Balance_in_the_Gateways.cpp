#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs()

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<vector<pair<int,char>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        char ch;
        cin >> u >> v >> ch;
        adj[u].push_back({v, ch});
        adj[v].push_back({u, ch});
    }
    vector<int> vis(n+1);
    int ans = INT_MAX;
    
    return 0;
}