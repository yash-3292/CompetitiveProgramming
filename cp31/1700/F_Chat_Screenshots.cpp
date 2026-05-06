#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<unordered_set<int>> adj(n+1);
        for(int i=0; i<k; i++){
            vector<int> arr(n);
            for(int j=0; j<n; j++){
                cin >> arr[j];
                if(j > 1){
                    adj[arr[j-1]].insert(arr[j]);
                }
            }
        }
        vector<int> indegree(n+1, 0);
        for(int i=1; i<=n; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=1; i<=n; i++) if(indegree[i] == 0) q.push(i);
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(cnt == n){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}