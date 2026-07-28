#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll f(int i, int prevSwap, vector<int>& a, vector<int>& b, vector<vector<ll>>& dp){
    if(i == a.size()) return 1;

    if(dp[i][prevSwap] != -1) return dp[i][prevSwap];

    ll swap = 0;
    ll notSwap = 0;
    if(i == 0){
        swap = f(i+1, 1, a, b, dp);
        notSwap = f(i+1, 0, a, b, dp);
    } else{
        if(prevSwap){
            if(a[i-1] <= a[i] && b[i-1] <= b[i]){
                swap = f(i+1, 1, a, b, dp);
            } 
            if(a[i-1] <= b[i] && b[i-1] <= a[i]){
                notSwap = f(i+1, 0, a, b, dp);
            }
        } else{
            if(a[i-1] <= a[i] && b[i-1] <= b[i]){
                notSwap = f(i+1, 0, a, b, dp);
            } 
            if(a[i-1] <= b[i] && b[i-1] <= a[i]){
                swap = f(i+1, 1, a, b, dp);
            }
        }
    }
    ll ans = (swap + notSwap) % mod;
    return dp[i][prevSwap] = ans;
}

void solve(){
    int n;
    cin >> n; 
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    vector<vector<ll>> dp(n, vector<ll>(2,-1));
    ll ans = f(0, 0, a, b, dp);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}