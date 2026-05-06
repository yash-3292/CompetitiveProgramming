#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

void dfs(int row, int col, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& arr){
    vis[row][col] = 1;
    for(int i=0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if(0 <= nrow && nrow < n && 0 <= ncol && ncol < m && arr[nrow][ncol] == '.' && !vis[nrow][ncol]){
            dfs(nrow, ncol, n, m, vis, arr);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && arr[i][j] == '.'){
                ans++;
                dfs(i, j, n, m, vis, arr);
            }
        }
    }
    cout << ans << endl;
    return 0;
}