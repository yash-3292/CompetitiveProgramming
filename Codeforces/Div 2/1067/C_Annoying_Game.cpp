#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int opt, vector<ll>& a, vector<ll>& b, ll &ans, vector<vector<ll>>& dp){
    if(i < 0) return 0;

    if(dp[i][opt] != -1) return dp[i][opt];

    ll answer = INT_MIN;
    if(opt){
        ll val1 = f(i-1, 0, a, b, ans, dp);
        answer = a[i] + b[i] + max(val1, (ll)0);
    }
    ll val2 = f(i-1, opt, a, b, ans, dp);
    answer = max(answer, a[i] + max(val2, (ll)0));

    ans = max(ans, answer);

    return dp[i][opt] = answer;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        ll ans = INT_MIN;
        vector<vector<ll>> dp(n, vector<ll>(2, -1));
        if(k&1){
            f(n-1, 1, a, b, ans, dp);
        } else{
            f(n-1, 0, a, b, ans, dp);
        }
        cout << ans << endl;
    }
    return 0;
}