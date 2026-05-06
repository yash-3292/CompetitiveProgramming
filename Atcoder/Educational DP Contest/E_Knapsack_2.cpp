#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n; 
    ll weight;
    cin >> n >> weight;
    vector<int> w(n+1), v(n+1);
    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += v[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(sum+1));
    for(int s=0; s<=sum; s++) dp[0][s] = 1e15;
    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int s=0; s<=sum; s++){
            ll ans = dp[i-1][s];
            if(s >= v[i]){
                ll take = w[i] + dp[i-1][s-v[i]];
                ans = min(ans, take);
            }
            dp[i][s] = ans;
        }
    }
    int maxi = 0;
    for(int s=0; s<=sum; s++){
        if(dp[n][s] <= weight) maxi = s;
    }
    cout << maxi << endl;
    return 0;
}