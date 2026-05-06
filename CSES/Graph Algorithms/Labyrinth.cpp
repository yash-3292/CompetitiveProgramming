#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};
char c[4] = {'U', 'R', 'D', 'L'};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    pair<int,int> start;
    pair<int,int> end;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'A') start = {i,j};
            if(arr[i][j] == 'B') end = {i, j};
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) parent[i][j] = {i,j};
    }
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    vector<vector<char>> ch(n, vector<char>(m, 'a'));
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int row = it.first;
        int col = it.second;
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(0 <= nrow && nrow < n && 0 <= ncol && ncol < m && (arr[nrow][ncol] == '.' || arr[nrow][ncol] == 'B') && !vis[nrow][ncol]){
                parent[nrow][ncol] = {row, col};
                vis[nrow][ncol] = 1;
                ch[nrow][ncol] = c[i];
                q.push({nrow, ncol});
            }
        }
    }
    if(!vis[end.first][end.second]){
        cout << "NO" << endl;
        return 0;
    } 
    int i = end.first;
    int j = end.second;
    string ans;
    while(!(i == start.first && j == start.second)){
        ans += ch[i][j];
        int ni = parent[i][j].first;
        int nj = parent[i][j].second;
        i = ni;
        j = nj;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}