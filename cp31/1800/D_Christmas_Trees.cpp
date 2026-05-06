#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    map<int,int> vis;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        vis[x] = 1;
        q.push({x, 0});
    }
    ll ans = 0;
    vector<int> arr;
    while(!q.empty()){
        auto it = q.front();
        int node = it.first;
        int dist = it.second;
        q.pop();
        if(dist != 0){
            ans += (ll)dist;
            arr.push_back(node);
            if(arr.size() == m) break;
        }
        if(vis.find(node-1) == vis.end()){
            vis[node-1] = 1;
            q.push({node-1, dist+1});
        }
        if(vis.find(node+1) == vis.end()){
            vis[node+1] = 1;
            q.push({node+1, dist+1});
        }
    }
    cout << ans << endl;
    for(auto it : arr) cout << it << " ";
    cout << endl;
    return 0;
}