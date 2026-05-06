#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool isValid(int i, int j, int n, int m){
    return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int i, int j, vector<vector<int>>& vis, vector<string>& arr){
    int n = arr.size();
    int m = arr[0].size();
    vis[i][j] = 1;
    for(int ind=0; ind<4; ind++){
        int ni = i + dr[ind];
        int nj = j + dc[ind];
        if(isValid(ni, nj, n, m) && arr[ni][nj] == '.' && (!vis[ni][nj])){
            dfs(ni, nj, vis, arr);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if((!vis[i][j]) && arr[i][j] == '.'){
                    dfs(i, j, vis, arr);
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((!vis[i][j]) && arr[i][j] == '.'){
                ans++;
                dfs(i, j, vis, arr);
            }
        }
    }
    cout << ans << endl;
    return 0;
}