#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int i, int j, int n, int m){
    return (0 <= i && i < n && 0 <= j && j < m);
}

int fW(int i1, int j1, int i2, int j2, vector<vector<int>>& arr1, vector<vector<int>>& arr2){
    if(i1 == i2){
        return arr1[i1][min(j1, j2)];
    } else{
        return arr2[min(i1,i2)][j1];
    }
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr1(n, vector<int>(m-1));
    vector<vector<int>> arr2(n-1, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m-1; j++){
            cin >> arr1[i][j];
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            cin >> arr2[i][j];
        }
    }
    if(k&1){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << -1 << " ";
            }
            cout << endl;
        }
        return 0;
    }
    k /= 2;
    vector<vector<vector<int>>> dist(k+1, vector<vector<int>>(n, vector<int>(m, 1e9)));
    // priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    queue<tuple<int, int, int, int>> pq;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[0][i][j] = 0;
            pq.push({0, 0, i, j});
        }
    }
    while(!pq.empty()){
        int d, step, i, j;
        tie(d, step, i, j) = pq.front();
        pq.pop();
        if(dist[step][i][j] < d) continue;
        if(step == k) continue;

        for(int ind=0; ind<4; ind++){
            int ni = i + dx[ind];
            int nj = j + dy[ind];
            if(isValid(ni, nj, n, m)){
                int w = fW(i, j, ni, nj, arr1, arr2);
                if(d + w < dist[step+1][ni][nj]){
                    dist[step+1][ni][nj] = d + w;
                    pq.push({dist[step+1][ni][nj], step+1, ni, nj});
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << dist[k][i][j]*2 << " ";
        }
        cout << endl;
    }
    return 0;
}