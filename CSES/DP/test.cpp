#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,x;
    cin >> n >> x;
    vector<int>c(n);
    for(int i = 0 ; i < n ; i++){
        cin >> c[i];
    }
    vector<int>dp(x+1,1e9);
    dp[0] = 0;
    for(int i = 1 ; i <= x ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i-c[j] >= 0){
                dp[i] = min(dp[i],1+dp[i-c[j]]);
            }
        }
    }
    if(dp[x] == 1e9) cout << -1 << "\n";
    else cout << dp[x] << "\n";
}