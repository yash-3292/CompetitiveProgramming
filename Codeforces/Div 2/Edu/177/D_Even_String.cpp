#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

ll modInv(ll a){
    return binpow(a, mod - 2);
}

const ll maxN = 1e6+10;

ll fact[maxN];
ll invFact[maxN];

void preFact(){
    fact[0] = 1;
    for(ll i = 1; i < maxN; i++){
        fact[i] = (i * fact[i - 1]) % mod;
    }
    invFact[maxN - 1] = modInv(fact[maxN - 1]);
    for(ll i = maxN - 2; i >= 0; i--){
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

ll f(ll i, ll sum, vector<ll>& arr, vector<vector<ll>>& dp){
    if(i == arr.size()){
        if(sum == 0) return 1;
        return 0;
    }

    if(dp[i][sum] != -1) return dp[i][sum];

    ll notTake = f(i+1, sum, arr, dp);
    ll take = 0;
    if(sum >= arr[i]) take = f(i+1, sum-arr[i], arr, dp);
    ll ans = (take + notTake) % mod;

    return dp[i][sum] = ans;
}

void solve(){
    vector<ll> arr;
    ll sum = 0;
    for(ll i=0; i<26; i++){
        ll x;
        cin >> x;
        sum += x;
        if(x > 0) arr.push_back(x);
    }    
    ll ans = (fact[sum/2] * fact[sum - sum/2]) % mod;
    for(auto it : arr){
        ans = (ans * invFact[it]) % mod;
    }
    vector<vector<ll>> dp(arr.size(), vector<ll>(sum/2+1, -1));
    ans = (ans * f(0, sum/2, arr, dp)) % mod;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preFact();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}