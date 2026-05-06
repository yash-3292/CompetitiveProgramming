#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
            }
        }
        if((n+m-1)&1){
            cout << "NO" << endl;
            continue;
        }
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(m));
        dp[0][0].first = arr[0][0];
        dp[0][0].second = arr[0][0];
        for(int j=1; j<m; j++){
            dp[0][j].first = dp[0][j-1].first + arr[0][j];
            dp[0][j].second = dp[0][j-1].second + arr[0][j];
        }
        for(int i=1; i<n; i++){
            dp[i][0].first = dp[i-1][0].first + arr[i][0];
            dp[i][0].second = dp[i-1][0].second + arr[i][0];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j].first = min(dp[i-1][j].first, dp[i][j-1].first) + arr[i][j];
                dp[i][j].second = max(dp[i-1][j].second, dp[i][j-1].second) + arr[i][j];
            }
        }
        if(dp[n-1][m-1].first <= 0 && 0 <= dp[n-1][m-1].second){
            cout << "YES" << endl; 
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}