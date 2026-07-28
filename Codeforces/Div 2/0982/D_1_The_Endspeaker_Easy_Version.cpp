#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll i, ll k, vector<ll>& a, vector<ll>& b, vector<ll>& preSum, vector<vector<ll>>& dp){
    if(i == a.size()){
        return 0;
    }

    if(dp[i][k] != -1) return dp[i][k];

    ll val1 = 1e16;
    ll val2 = 1e16;
    if(k < b.size()-1){
        val1 = f(i, k+1, a, b, preSum, dp);
    }
    if(a[i] <= b[k]){
        ll l = i;
        ll r = a.size()-1;
        ll ind = i;
        while(l <= r){
            ll mid = l + (r-l)/2;
            ll sum = preSum[mid];
            if(i > 0) sum -= preSum[i-1];
            if(sum <= b[k]){
                ind = mid;
                l = mid+1;
            } else{
                r = mid-1;
            }
        }   
        val2 = b.size() - k - 1 + f(ind+1, k, a, b, preSum, dp);
    }
    ll ans = min(val1, val2);

    return dp[i][k] = ans;
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<m; i++) cin >> b[i];
    vector<ll> preSum(n);
    preSum[0] = a[0];
    for(ll i=1; i<n; i++) preSum[i] = preSum[i-1] + a[i];
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    ll ans = f(0, 0, a, b, preSum, dp);
    if(ans == 1e16) cout << -1 << endl;
    else cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}