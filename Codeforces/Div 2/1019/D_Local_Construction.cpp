#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int maxi = 0;
    for(int i=0; i<n; i++) maxi = max(maxi, arr[i]);
    for(int i=0; i<n; i++) if(arr[i] == -1) arr[i] = maxi + 1;
    vector<vector<pair<int,int>>> temp;
    vector<pair<int,int>> edge;
    for(int i=1; i<=maxi; i++){
        vector<pair<int,int>> t;
        for(int j=0; j<n; j++){
            if(arr[j] > i) t.push_back({j,1});
            else if(arr[j] == i) t.push_back({j,0});
        }
        temp.push_back(t);
    }
    for(int i=0; i<maxi; i++){
        int sz = temp[i].size();
        int flag = 0;
        for(int j=0; j<sz; j++){
            if(temp[i][j].second == 1){
                flag = 1;
                continue;
            }
            if(i%2 == 0){
                if(!flag){
                    if(j != sz-1){
                        edge.push_back({temp[i][j+1].first, temp[i][j].first});
                    }
                    continue;
                }
                if(j != 0 && temp[i][j-1].second == 1){
                    edge.push_back({temp[i][j-1].first, temp[i][j].first});
                }
                if(j != sz-1){
                    if(temp[i][j+1].second == 1){
                        edge.push_back({temp[i][j+1].first, temp[i][j].first});
                    } else{
                        edge.push_back({temp[i][j].first, temp[i][j+1].first});
                    }
                }
            } else{
                if(!flag){
                    if(j != sz-1){
                        edge.push_back({temp[i][j+1].first, temp[i][j].first});
                        swap(edge.back().first, edge.back().second);
                    }
                    continue;
                }
                if(j != 0 && temp[i][j-1].second == 1){
                    edge.push_back({temp[i][j-1].first, temp[i][j].first});
                    swap(edge.back().first, edge.back().second);
                }
                if(j != sz-1){
                    if(temp[i][j+1].second == 1){
                        edge.push_back({temp[i][j+1].first, temp[i][j].first});
                        swap(edge.back().first, edge.back().second); 
                    } else{
                        edge.push_back({temp[i][j].first, temp[i][j+1].first});
                        swap(edge.back().first, edge.back().second);
                    }
                }
            }
        }
    }
    vector<int> ans(n);
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    for(auto it : edge){
        adj[it.first].push_back(it.second);
        indegree[it.second]++;
    }
    queue<int> q;
    for(int i=0; i<n; i++) if(indegree[i] == 0) q.push(i);
    int cnt = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans[node] = cnt++;
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
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