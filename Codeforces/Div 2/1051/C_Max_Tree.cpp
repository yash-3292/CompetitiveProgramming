#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);
    for(int i=0; i<n-1; i++){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if(u > v) swap(u, v);
        if(x > y){
            adj[v].push_back(u);
            indegree[u]++;
        } else{
            adj[u].push_back(v);
            indegree[v]++;
        }
    }
    vector<int> ans(n+1);
    int x = 1;
    queue<int> q;
    for(int i=1; i<=n; i++) if(indegree[i] == 0) q.push(i);
    while(!q.empty()){
        int node = q.front();
        ans[node] = x;
        x++;
        q.pop();
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}