#include<bits/stdc++.h>
using namespace std;

bool solve(int x, int y, vector<vector<int>>& arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<int> temp(m);
    for(int i=0; i<m; i++){
        temp[i] = i+1;
        if(temp[i] == x) temp[i] = y;
        else if(temp[i] == y) temp[i] = x;
    }
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++){
            if(temp[j] != arr[i][j]) cnt++;
        }
        if(cnt != 0 && cnt != 2) return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    bool flag = solve(1, 1, arr);
    if(flag){
        cout << "YES" << endl;
        return 0;
    }
    for(int i=1; i<m; i++){
        for(int j=i+1; j<=m; j++){
            flag = solve(i, j, arr);
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}