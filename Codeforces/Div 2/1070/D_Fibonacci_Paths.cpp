#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ll> arr(n+1);
        for(int i=1; i<=n; i++) cin >> arr[i];
        vector<unordered_map<ll,int>> mpp(n+1);
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1, 0);
        ll ans = 0;
        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            mpp[v][arr[v]+arr[u]] += 1;
            ans++;
            if(arr[u] < arr[v]){
                adj[u].push_back(v);
                indegree[v]++;
            }
        }
        queue<int> q;
        // for(int i=1; i<=n; i++) cout << indegree[i] << " ";
        // cout << endl;
        for(int i=1; i<=n; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            // cout << node << " " << ans << " " << endl;
            for(auto it : adj[node]){
                if(mpp[node].find(arr[it]) != mpp[node].end()){
                    ans = (ans + mpp[node][arr[it]])%mod;
                    mpp[it][arr[it]+arr[node]] = (mpp[it][arr[it]+arr[node]] + mpp[node][arr[it]])%mod;
                }
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        } 
        cout << ans << endl;
    }
    return 0;
}