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

int calc(int i, int j, int k, int x, int y, int z){
    return (k*x*y + i*y + j);
}

int dx[6] = {-1, 0, 0, 1, 0, 0};
int dy[6] = {0, 0, 1, 0, 0, -1};
int dz[6] = {0, -1, 0, 0, 1, 0};

bool isValid(int i, int j, int k, int x, int y, int z){
    return (0 <= i && i < x && 0 <= j && j < y && 0 <= k && k < z);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        vector<vector<string>> arr(z, vector<string>(x));
        for(int k=0; k<z; k++){
            for(int i=0; i<x; i++){
                cin >> arr[k][i];
            }
        }
        int n = x*y*z;
        DisjointSet dsu(n);
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                for(int k=0; k<z; k++){
                    if(arr[k][i][j] == '.'){
                        for(int ind = 0; ind<6; ind++){
                            int ni = i + dx[ind];
                            int nj = j + dy[ind];
                            int nk = k + dz[ind];
                            if(isValid(ni, nj, nk, x, y, z) && arr[nk][ni][nj] == '.'){
                                int u = calc(i, j, k, x, y, z);
                                int v = calc(ni, nj, nk, x, y, z);
                                dsu.unionBySize(u, v);
                            }
                        }
                    }
                }
            }
        }
        // cout << "hi" << endl;
        int maxi = 0;
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                set<int> st;
                for(int k=0; k<z; k++){
                    if(arr[k][i][j] == '.'){
                        int u = calc(i, j, k, x, y, z);
                        st.insert(dsu.findUPar(u));
                    }
                }
                int ans = 0;
                for(auto it : st){
                    ans += dsu.size[it];
                }
                maxi = max(maxi, ans);
            }
        }
        cout << maxi << endl;
    }
    return 0;
}