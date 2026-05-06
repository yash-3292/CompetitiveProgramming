#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 1e6;
int spf[sz];

void pre(){
    for(int i=0; i<sz; i++) spf[i] = i;
    for(int i=2; i<sz; i++){
        if(spf[i] == i){
            for(int j=2*i; j<sz; j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void factor(int n, vector<int>& ans){
    while(n > 1){
        int f = spf[n];
        ans.push_back(f);
        while(n%f == 0) n /= f;
    }
}

int main(){
    pre();
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<pair<int,int>>> adj(3e5+1);
    int s, t;
    cin >> s >> t;
    if(s == t){
        cout << 1 << endl;
        cout << s << endl;
        return 0;
    } 
    s--;
    t--;
    vector<int> start;
    vector<int> end;
    for(int i=0; i<n; i++){
        vector<int> temp;
        factor(arr[i], temp);
        int m = temp.size();
        for(int j=0; j<m; j++){
            for(int k=j+1; k<m; k++){
                int u = temp[j];
                int v = temp[k];
                adj[u].push_back({v, i});
                adj[v].push_back({u, i});
            }
        }
        if(i == s) start = temp;
        if(i == t) end = temp;
    }
    vector<int> dist(3e5+1, 1e9);
    vector<int> par(3e5+1, -1);
    vector<int> ed(3e5+1);
    queue<int> q;
    for(auto it : start){
        dist[it] = 0;
        q.push(it);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            int v = it.first;
            int e = it.second;
            if(dist[node]+1 < dist[v]){
                dist[v] = dist[node]+1;
                par[v] = node;
                ed[v] = e;
                q.push(v);
            }
        }
    }
    int dis = 1e9;
    int i = -1;
    for(auto it : end){
        if(dist[it] < dis){
            dis = dist[it];
            i = it;
        }
    }
    if(i == -1){
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(t);
    while(dist[i] != 0){
        ans.push_back(ed[i]);
        i = par[i];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto it : ans) cout << it+1 << " ";
    cout << endl;
    return 0;
}