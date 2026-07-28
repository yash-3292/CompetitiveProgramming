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
    if(arr[0][0] == '1'){
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> ans;
    for(int i=n-1; i>=1; i--){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '1'){
                ans.push_back({i-1, j, i, j});
            }
        }
    }
    for(int j=m-1; j>=1; j--){
        if(arr[0][j] == '1'){
            ans.push_back({0, j-1, 0, j});
        }
    }
    cout << ans.size() << endl;
    for(auto it : ans){
        cout << it[0]+1 << " " << it[1]+1 << " " << it[2]+1 << " " << it[3]+1 << endl;
    }
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