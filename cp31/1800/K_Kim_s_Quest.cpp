#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll f(int i, int num, int l, vector<int>& arr, vector<vector<vector<ll>>>& dp){
    if(i < 0){
        if(l == 3) return 1;
        return 0;
    }

    if(dp[i][num][l] != -1) return dp[i][num][l];

    ll notTake = f(i-1, num, l, arr, dp);
    ll take = 0;
    int next = ((num>>1) + (num&1))%2;
    if(arr[i] == next){
        take = f(i-1, (((num<<1)&3)|next), min(l+1, 3), arr, dp);
    }

    ll ans = (take + notTake)%mod;
    return dp[i][num][l] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr[i] = (x&1);
    }
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(4, vector<ll>(4, -1)));
    ll ans = 0;
    for(int i=0; i<4; i++){
        ans += f(n-1, i, 0, arr, dp);
        ans = ans%mod;
    }
    cout << ans << endl;
    return 0;
}