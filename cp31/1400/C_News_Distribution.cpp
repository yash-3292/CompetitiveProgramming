#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, temp);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        int prev = -1;
        while(k--){
            int x;
            cin >> x;
            if(prev != -1){
                adj[x].push_back(prev);
                adj[prev].push_back(x);
            }
            prev = x;
        }
    }
    vector<vector<int>> ans;
    vector<int> vis(n+1,0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(i, adj, vis, temp);
            ans.push_back(temp);
        }
    }
    vector<int> freq(n+1);
    for(auto arr : ans){
        for(auto val : arr){
            freq[val] = arr.size();
        }
    }
    
    for(int i=1; i<=n; i++) cout << freq[i] << " ";
    cout << endl;
    return 0;
}