#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        if(n == 1){
            if(k == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
            continue;
        }
        vector<int> vis(n+1,0);
        int cnt = n;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                cnt--;
                dfs(i, adj, vis);
            }
        }
        if(k < (ll)cnt){
            cout << "No" << endl;
        } else{
            ll diff = k-cnt;
            if(diff%2 == 0){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}