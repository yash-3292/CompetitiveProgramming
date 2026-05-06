#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int opt, vector<int>& a, vector<int>& b, vector<vector<ll>>& dp){
    if(i < 0) return 0;

    if(dp[i][opt] != -1) return dp[i][opt];
    
    ll ans;
    if(opt){
        ll val1 = f(i-1, 1, a, b, dp) - (ll)a[i];
        ll val2 = (ll)b[i] - f(i-1, 0, a, b, dp);
        ans = max(val1, val2);
    } else{
        ll val1 = f(i-1, 0, a, b, dp) - (ll)a[i];
        ll val2 = (ll)b[i] - f(i-1, 1, a, b, dp);
        ans = min(val1, val2);
    }

    return dp[i][opt] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<vector<ll>> dp(n, vector<ll>(2,-1));
        ll ans = f(n-1, 1, a, b, dp);
        cout << ans << endl;
    }
    return 0;
}