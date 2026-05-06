#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int w, vector<int>& weight, vector<int>& value, vector<vector<ll>>& dp){
    if(i < 0) return 0;

    if(dp[i][w] != -1) return dp[i][w];
    ll notTake = f(i-1, w, weight, value, dp);
    ll take = 0;
    if(weight[i] <= w) take = value[i] + f(i-1, w-weight[i], weight, value, dp);

    return dp[i][w] = max(notTake, take);
}

int main(){
    int n, w;
    cin >> n >> w;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0; i<n; i++) cin >> weight[i] >> value[i];
    vector<vector<ll>> dp(n, vector<ll>(w+1, -1)); 
    ll ans = f(n-1, w, weight, value, dp);
    cout << ans << endl;
    return 0;
}