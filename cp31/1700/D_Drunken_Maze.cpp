#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    pair<int,int> s;
    pair<int,int> t;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin >> x;
            if(x == '#') arr[i][j] = 0;
            else arr[i][j] = 1;
            if(x == 'S'){
                s.first = i;
                s.second = j;
            } else if(x == 'T'){
                t.first = i;
                t.second = j;
            }
        }
    }
    int dist[n][m][4][4];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int prev=0; prev<4; prev++){
                for(int num=0; num<4; num++){
                    dist[i][j][prev][num] = 1e9;
                }
            }
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) dist[s.first][s.second][i][j] = 0;
    }
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    queue<vector<int>> q;
    q.push({s.first, s.second, 0, -1, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int row = it[0];
        int col = it[1];
        int dis = it[2];
        int prev = it[3];
        int num = it[4];
        //  cout << row << " " << col << "=>";
        for(int i=0; i<4; i++){
            int newr = row + dr[i];
            int newc = col + dc[i];
            // cout << newr << " " << newc << endl;
            if(newr>=0 && newr<n && newc>=0 && newc<m && arr[newr][newc] == 1){
                if(i != prev){
                    if(dis+1 < dist[newr][newc][i][1]){
                        dist[newr][newc][i][1] = dis+1;
                        q.push({newr, newc, dist[newr][newc][i][1], i, 1});
                    }
                } else{
                    if(num == 3) continue;
                    if(dis+1 < dist[newr][newc][i][num+1]){
                        dist[newr][newc][i][num+1] = dis+1;
                        q.push({newr, newc, dist[newr][newc][i][num+1], i, num+1});
                    }
                }
            } 
        }
    }
    int ans = 1e9;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++) ans = min(ans, dist[t.first][t.second][i][j]);
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}