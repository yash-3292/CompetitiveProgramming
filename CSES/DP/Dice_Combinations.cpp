#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll f(int n, vector<ll>& dp){
    if(n==0) return 1;
    
    if(dp[n] != -1) return dp[n];

    ll ans = 0;
    for(int i=1; i<=6; i++){
        if(n >= i){
            ans = (ans + f(n-i, dp))%mod;
        }
    }
    
    return dp[n] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<ll> dp(n+1, -1);
    ll ans = f(n, dp);
    cout << ans << endl;
    return 0;
}