#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        } else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<vector<int>> conn(n);
        for(int i=0; i<n-1; i++){
            int val = abs(arr[i]-arr[i+1]);
            conn[val].push_back(i);
        }
        ll ans = 0;
        DisjointSet ds(n);
        vector<ll> v;
        for(int i=n-1; i>=1; i--){
            for(auto u : conn[i]){
                int v = u+1;
                int ulp_u = ds.findUPar(u);
                int ulp_v = ds.findUPar(v);
                if(ulp_u == ulp_v) continue;
                ans += (ll)ds.size[ulp_u] * (ll)ds.size[ulp_v];
                ds.unionBySize(u, v);
            }
            v.push_back(ans);
        }
        reverse(v.begin(), v.end());
        for(auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}