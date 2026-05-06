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

bool isTree(int n, vector<pair<int,int>>& edge){
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++) {
        int u = edge[i].first;
        int v = edge[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    dfs(0, adj, vis);
    for(int i=0; i<n; i++) if(!vis[i]) return false;
    return true;
}

void conn(int n, vector<pair<int,int>>& edge, vector<string>& temp){
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++) {
        int u = edge[i].first;
        int v = edge[i].second;
        adj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++){
        dfs(i, adj, vis);
        string s;
        for(int j=0; j<n; j++){
            if(vis[j]) s += '1';
            else s += '0';
            vis[j] = 0;
        }
        temp.push_back(s);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<vector<int>> adj(n);
        vector<unordered_set<int>> child(n);
        vector<int> indegree(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(arr[i][j] == '1'){
                    adj[j].push_back(i);
                    indegree[i]++;
                } 
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                child[it].insert(node);
                for(auto ch : child[node]){
                    child[it].erase(ch);
                }
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        } 
        vector<pair<int,int>> ans;
        for(int i=0; i<n; i++){
            for(auto ch : child[i]) ans.push_back({i, ch});
        }
        if(ans.size() != n-1){
            cout << "No" << endl;
            continue;
        }
        if(!isTree(n, ans)){
            cout << "No" << endl;
            continue;
        }
        vector<string> temp;
        conn(n, ans, temp);
        if(temp != arr){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        for(auto it : ans){
            cout << it.first+1 << " " << it.second+1 << endl;
        }
    }
    return 0;
}