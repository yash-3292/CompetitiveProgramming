#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int node, int day, int w){
    return node * w + day;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> edge;
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            edge.push_back({u,v});
            edge.push_back({v,u});
        }
        for(int i=0; i<n; i++){
            edge.push_back({i,i});
        }
        // for(auto it : edge) cout << it.first << " " << it.second << endl;
        // cout << endl;
        int w;
        cin >> w;
        vector<string> s;
        for(int i=0; i<n; i++){
            string si;
            cin >> si;
            s.push_back(si);
        }
        vector<vector<int>> adj(n*w);
        vector<int> indegree(n*w, 0);
        for(auto it : edge){
            int node1 = it.first;
            int node2 = it.second;
            for(int day=0; day<w; day++){
                if(s[node1][day] == 'o' && s[node2][(day+1)%w] == 'o'){
                    int u = f(node1, day, w);
                    int v = f(node2, (day+1)%w, w);
                    adj[u].push_back(v);
                    indegree[v]++;
                }
            }
        }
        queue<int> q;
        for(int i=0; i<n*w; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        int flag = 0;
        for(int i=0; i<n*w; i++){
            if(indegree[i] != 0 && (i%w == 0)){
                flag = 1;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}