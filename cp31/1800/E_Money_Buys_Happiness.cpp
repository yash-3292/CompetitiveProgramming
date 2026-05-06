#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, x;
        cin >> m >> x;
        vector<int> c(m+1), h(m+1);
        for(int i=1; i<=m; i++) cin >> c[i] >> h[i];
        int sum = 0;
        for(int i=1; i<=m; i++) sum += h[i];
        vector<vector<ll>> dp(m+1, vector<ll>(sum+1));
        dp[0][0] = 0;
        for(int s=1; s<=sum; s++) dp[0][s] = 1e17;
        int happiness = 0;
        for(int i=1; i<=m; i++){
            for(int s=0; s<=sum; s++){
                ll ans = dp[i-1][s];
                if(h[i] <= s){
                    ll cost = c[i] + dp[i-1][s-h[i]];
                    if(cost <= (ll)(i-1)*(ll)x){
                        happiness = max(happiness, s);
                        ans = min(ans, cost);
                    }
                }
                dp[i][s] = ans;
            }
        }
        cout << happiness << endl;
    }
    return 0;
}