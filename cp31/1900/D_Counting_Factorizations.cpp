#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

ll modinv(ll a){
    return binpow(a, mod-2);
}

const int sz = 1e6+7;
bool prime[sz];

void calcprime(){
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<sz; i++) prime[i] = true;
    for(int i=2; i*i<sz; i++){
        if(prime[i]){
            for(int j=i*i; j<sz; j+=i){
                prime[j] = false;
            }
        }
    }
}

vector<ll> fact;
vector<ll> invfact;
void calcfact(int n){
    fact.resize(n+1);
    invfact.resize(n+1);
    fact[0] = 1;
    for(ll i=1; i<=n; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    invfact[0] = 1;
    invfact[n] = modinv(fact[n]);
    for(ll i=n-1; i>=1; i--){
        invfact[i] = (invfact[i+1] * (i+1)) % mod;
    }
}

ll f(int i, int cnt, int sz, int thres, vector<int>& arr, unordered_map<int,int>& mpp2, vector<vector<ll>>& dp){
    if(i == sz){
        if(cnt == thres) return 1;
        else return 0; 
    }

    if(dp[i][cnt] != -1) return dp[i][cnt];

    ll take = f(i+1, cnt, sz, thres, arr, mpp2, dp);
    ll notTake = 0;
    if(cnt < thres){
        ll x = f(i+1, cnt+1, sz, thres, arr, mpp2, dp);
        if(mpp2.find(arr[i]) != mpp2.end()){
            x = (x * fact[mpp2[arr[i]]]) % mod;
            x = (x * invfact[mpp2[arr[i]]+1]) % mod;
        } 
        notTake = x;
    }

    ll ans = (take + notTake) % mod;
    return dp[i][cnt] = ans;
}

void solve(){
    int n;
    cin >> n;
    calcfact(n);
    unordered_map<int,int> mpp1;
    unordered_map<int,int> mpp2;
    for(int i=0; i<2*n; i++){
        int x;
        cin >> x;
        if(prime[x]){
            if(mpp1.find(x) == mpp1.end()){
                mpp1[x]++;
            } else{
                mpp2[x]++;
            }
        } else{
            mpp2[x]++;
        }
    }
    vector<int> arr;
    for(auto it : mpp1){
        arr.push_back(it.first);
    }
    int sz = arr.size();
    if(sz < n){
        cout << 0 << endl;
        return;
    }
    ll ans = fact[n];
    for(auto it : mpp2){
        if(it.second > 1){
            ans = (ans * invfact[it.second]) % mod;
        }
    }
    int thres = sz - n;
    vector<vector<ll>> dp(sz, vector<ll>(thres+1,-1));
    ll ans1 = f(0, 0, sz, thres, arr, mpp2, dp);
    ans = (ans * ans1) % mod;
    cout << ans << endl;
}

int main(){
    calcprime();
    solve();
    return 0;
}