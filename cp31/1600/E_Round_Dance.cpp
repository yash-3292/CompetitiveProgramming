#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isCycle(int node, int parent, int first, vector<vector<int>>& adj, vector<int>& vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(it != parent && it == first) return true;
        if(!vis[it]){
            if(isCycle(it, node, first, adj, vis)) return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for(int i=1; i<=n; i++){
            int j;
            cin >> j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        int maxi = 0;
        int cycle = 0;
        int notcycle = 0;
        vector<int> vis(n+1, 0);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                maxi++;
                if(isCycle(i, -1, i, adj, vis)) cycle++;
                else notcycle++;
            }
        }
        int mini = cycle;
        if(notcycle) mini++;
        cout << mini << " " << maxi << endl;
    }
    return 0;
}