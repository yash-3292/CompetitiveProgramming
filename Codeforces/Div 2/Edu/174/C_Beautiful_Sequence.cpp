#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll f(int i, int state, vector<int>& arr, vector<vector<ll>>& dp){
    if(i == arr.size()){
        if(state == 3) return 1;
        return 0;
    }

    if(dp[i][state] != -1) return dp[i][state];
    
    ll take = 0;
    ll notTake = f(i+1, state, arr, dp);
    if(state == 0){
        if(arr[i] == 1){
            take = f(i+1, 1, arr, dp);
        }
    } else if(state == 1){
        if(arr[i] == 2){
            take = f(i+1, 2, arr, dp);
        }
    } else if(state == 2){
        if(arr[i] == 2){
            take = f(i+1, 2, arr, dp);
        } else if(arr[i] == 3){
            take = f(i+1, 3, arr, dp);
        }
    }
    ll ans = (take + notTake) % mod;

    return dp[i][state] = ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<ll>> dp(n, vector<ll>(4,-1));
    ll ans = f(0, 0, arr, dp);
    cout << ans << endl;
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