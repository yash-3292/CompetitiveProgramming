#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int,int> dfs(int node, vector<vector<int>>& adj, string s, int &cnt){
    pair<int,int> ans = {0,0};
    if(s[node] == 'W') ans.first++;
    else ans.second++;
    for(int it : adj[node]){
        pair<int,int> temp = dfs(it, adj, s, cnt);
        ans.first += temp.first;
        ans.second += temp.second;
    }
    if(ans.first == ans.second) cnt++;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for(int i=1; i<n; i++){
            int x;
            cin >> x;
            adj[x-1].push_back(i);
        }
        string s;
        cin >> s;
        int cnt = 0;
        dfs(0, adj, s, cnt);
        cout << cnt << endl;
    }
    return 0;
}