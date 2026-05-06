#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int ans;
            if(a[i-1] == b[j-1]){
                ans = 1 + dp[i-1][j-1];
            } else{
                ans = max(dp[i-1][j], dp[i][j-1]);
            }
            dp[i][j] = ans;
        }
    }
    int ans = dp[n][m];
    cout << ans << "\n";
    int i = n; 
    int j = m;
    vector<int> ansv;
    while(i != 0 && j != 0){
        if(a[i-1] == b[j-1]){
            ansv.push_back(a[i-1]);
            i--;
            j--;
        } else{
            if(dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(ansv.begin(), ansv.end());
    for(auto it : ansv) cout << it << " ";
    cout << endl;
    return 0;
}