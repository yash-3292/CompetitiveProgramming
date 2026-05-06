#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class DisjointSet {
    vector<int> rank, parent, size;
public:
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> arr;
        for(int i=0; i<m; i++){
            int x, y, s;
            cin >> x >> y >> s;
            arr.push_back({s, x, y});
        }
        sort(arr.begin(), arr.end());
        vector<int> arr1;
        vector<int> arr2;
        DisjointSet dsu(n);
        for(auto it : arr){
            int val = it[0];
            int u = it[1];
            int v = it[2];
            if(dsu.findUPar(u) != dsu.findUPar(v)){
                dsu.unionByRank(u, v);
                arr1.push_back(val);
            } else{
                arr2.push_back(val);
            }
        }
        ll ans = 0;
        if(arr1.back() >= k){
            for(auto it : arr1){
                if(it > k) ans += (ll)(it - k);
            }
        } else{
            ans = (k - arr1.back());
            for(auto it : arr2){
                ans = min(ans, (ll)abs(it-k));
            }
        }
        cout << ans << endl;
    }
    return 0;
}