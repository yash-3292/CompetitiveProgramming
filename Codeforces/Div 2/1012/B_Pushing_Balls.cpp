#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> preCol(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0){
                if(arr[i][j] == '1') preCol[i][j] = 1;
                continue;
            }
            if(preCol[i-1][j] && arr[i][j] == '1'){
                preCol[i][j] = 1;
            }
        }
    }
    vector<vector<int>> preRow(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j == 0){
                if(arr[i][j] == '1') preRow[i][j] = 1;
                continue;
            }
            if(preRow[i][j-1] && arr[i][j] == '1'){
                preRow[i][j] = 1;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] == '1'){
                if(preRow[i][j] || preCol[i][j]) continue;
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}