#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    if(s == "first"){
        int t;
        cin >> t;
        while(t--){
            int n, m;
            cin >> n >> m;
            vector<vector<int>> adj(n+1);
            for(int i=0; i<m; i++){
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<int> dist(n+1, INT_MAX);
            dist[1] = 0;
            queue<int> q;
            q.push(1);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    if(dist[node] + 1 < dist[it]){
                        dist[it] = dist[node] + 1;
                        q.push(it);
                    }
                }
            }
            for(int i=1; i<=n; i++){
                int val = dist[i]%3;
                if(val == 0) cout << "r";
                else if(val == 1) cout << "g";
                else cout << "b";
            }
            cout << endl;
        }
    } else{
        int t;
        cin >> t;
        while(t--){
            int q;
            cin >> q;
            while(q--){
                int n;
                cin >> n;
                string c;
                cin >> c;
                int ri = -1;
                int gi = -1;
                int bi = -1;
                for(int i=0; i<n; i++){
                    if(c[i] == 'r'){
                        ri = i;
                    } 
                    else if(c[i] == 'g'){
                        gi = i;   
                    }
                    else{
                        bi = i;
                    } 
                }
                // cout << ri << " " << gi << " " << bi << " ";
                if(ri == -1 && gi == -1){
                    cout << bi+1 << endl;
                } else if(gi == -1 && bi == -1){
                    cout << ri+1 << endl;
                } else if(ri == -1 && bi == -1){
                    cout << gi+1 << endl;
                } else if(ri == -1){
                    cout << bi+1 << endl;
                } else if(gi == -1){
                    cout << ri+1 << endl;
                } else{
                    cout << gi+1 << endl;
                }
            }
        }
    }
    return 0;
}