#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    map<int,int> freq;
    map<int,int> comm;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            freq[arr[i][j]]++;
            if(j+1 < m && arr[i][j] == arr[i][j+1]){
                comm[arr[i][j]] = 1;
            } 
            if(i+1 < n && arr[i][j] == arr[i+1][j]){
                comm[arr[i][j]] = 1;
            }
        }
    }
    int ans = 0;
    int maxi = 0;
    for(auto it : freq){
        if(comm.find(it.first) != comm.end()){
            ans += 2;
            maxi = max(maxi, 2);
        } else{
            ans += 1;
            maxi = max(maxi, 1);
        }
    }
    ans -= maxi;
    cout << ans << endl;
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