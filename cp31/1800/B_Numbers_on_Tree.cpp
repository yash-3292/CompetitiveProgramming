#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int isValid(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& c, int& flag){
    vis[node] = 1;
    int cnt = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            cnt += isValid(it, adj, vis, c, flag);
        }
    }
    if(c[node] > cnt) flag = 0;
    cnt++;
    return cnt;
}

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& c, vector<int>& arr, vector<int>& a){
    vis[node] = 1;
    a[node] = *(arr.begin() + c[node]);
    arr.erase(arr.begin()+c[node]);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, c, arr, a);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> c(n+1);
    int root = -1;
    for(int i=1; i<=n; i++){
        int p;
        cin >> p >> c[i];
        if(p != 0) adj[p].push_back(i);
        else root = i;
    }
    vector<int> vis(n+1, 0);
    int flag = 1;
    isValid(root, adj, vis, c, flag);
    if(!flag){
        cout << "NO" << endl;
        return 0;
    }
    for(int i=0; i<=n; i++) vis[i] = 0; 
    vector<int> arr(n);
    for(int i=0; i<n; i++) arr[i] = i+1;
    vector<int> a(n+1);
    dfs(root, adj, vis, c, arr, a);
    cout << "YES" << endl;
    for(int i=1; i<=n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}