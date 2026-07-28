#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int node, int vis, vector<vector<int>>& adj, vector<vector<int>>& dp){
    int ans = 1;

    if(dp[node][vis] != -1) return dp[node][vis];

    for(auto it : adj[node]){
        if(!(vis&(1<<it))){
            int val = 1 + f(it, (vis|(1<<node)), adj, dp);
            ans = max(ans, val);
        }
    }
    return dp[node][vis] = ans;
}

void solve(){
    int n;
    cin >> n;
    set<pair<int,int>> edge;
    unordered_map<string,vector<int>> genre, author;
    for(int i=0; i<n; i++){
        string g, a;
        cin >> g >> a;
        genre[g].push_back(i);
        author[a].push_back(i);
    }
    for(auto it : genre){
        int sz = it.second.size();
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                edge.insert({it.second[i],it.second[j]});
                edge.insert({it.second[j],it.second[i]});
            }
        }
    }
    for(auto it : author){
        int sz = it.second.size();
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                edge.insert({it.second[i],it.second[j]});
                edge.insert({it.second[j],it.second[i]});
            }
        }
    }
    vector<vector<int>> adj(n);
    for(auto it : edge){
        adj[it.first].push_back(it.second);
    }
    vector<vector<int>> dp(n, vector<int>((1<<n), -1));
    int ans = 1;
    for(int i=0; i<n; i++){
        ans = max(ans, f(i, 0, adj, dp));
    }
    ans = n - ans;
    cout << ans << endl;
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