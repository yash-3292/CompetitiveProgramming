#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int chance, vector<int>& a, vector<int>& b, vector<pair<ll,ll>>& dp){
    int n = a.size();
    if(i >= n) return 0;

    if(chance){
        if(dp[i].first != -1) return dp[i].first;
        ll ans = max((ll)a[i]+f(i+1, !chance, a, b, dp), f(i+1, chance, a, b, dp));
        return dp[i].first = ans;
    } else{
        if(dp[i].second != -1) return dp[i].second;
        ll ans = max((ll)b[i]+f(i+1, !chance, a, b, dp), f(i+1, chance, a, b, dp));
        return dp[i].second = ans;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    vector<pair<ll,ll>> dp(n, {-1,-1});
    ll ans = max(f(0,0,a,b,dp), f(0,1,a,b,dp));
    cout << ans << endl;
    return 0;
}