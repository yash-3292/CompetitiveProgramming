#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    int y = n+1;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v,y});
        adj[v].push_back({u,y});
        y++;
    }
    int x = 1;
    for(int i=1; i<=n; i++){
        if(adj[i].empty()){
            cout << 1 << endl;
            cout << x << " " << i << endl;
            x++;
            continue;
        }
        cout << 2*adj[i].size() << endl;
        for(auto it : adj[i]){
            cout << x << " " << i << endl;
            cout << x << " " << it.second << endl;
            x++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}