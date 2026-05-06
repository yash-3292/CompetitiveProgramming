#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int j, int n, vector<int>& arr, vector<vector<ll>>& dp){
    if(i > j) return 0;

    if(dp[i][j] != LLONG_MIN) return dp[i][j];

    int len = j-i+1;
    ll ans;
    if((n-len)%2 == 0){
        ans = max((ll)arr[i] + f(i+1, j, n, arr, dp), (ll)arr[j] + f(i, j-1, n, arr, dp));
    } else{
        ans = min(f(i+1, j, n, arr, dp), f(i, j-1, n, arr, dp));
    }
    return dp[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<ll>> dp(n, vector<ll>(n,LLONG_MIN));
    ll ans = f(0, n-1, n, arr, dp);
    cout << ans << endl;
    return 0;
}