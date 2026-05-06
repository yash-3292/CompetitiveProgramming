#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n, vector<ll>& dp){
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    vector<ll> arr;
    ll temp = n;
    while(temp > 0){
        ll d = temp%10;
        arr.push_back(d);
        temp /= 10;
    }
    ll ans = LLONG_MAX;
    for(auto it : arr){
        if(it){
            ll val = f(n-it, dp);
            ans = min(ans, val+1);
        }
    }
    return dp[n] = ans;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> dp(n+1, -1);
    ll ans = f(n, dp);
    cout << ans << endl;
    return 0;
}