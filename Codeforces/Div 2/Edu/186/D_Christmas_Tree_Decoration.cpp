#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(b == 0 || a == 1) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % mod;
        b >>= 1;
        a = (a*a) % mod;
    }
    return res;
}

ll modInv(ll a){
    return binpow(a, mod-2);
}

ll fact(ll n){
    ll ans = 1;
    for(ll i=1; i<=n; i++){
        ans = (ans*i)%mod;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n+1);
        for(ll i=0; i<=n; i++) cin >> arr[i];
        ll sum = 0;
        for(ll i=0; i<=n; i++) sum += arr[i];
        ll x = sum / n;
        ll y = sum % n;
        bool flag = true;
        ll cnt = 0;
        for(ll i=1; i<=n; i++){
            if(arr[i] > x+1) flag = false;
            if(arr[i] == x+1) cnt++;
        }
        if((!flag) || cnt > y){
            cout << 0 << endl;
            continue;
        }
        ll ans = (fact(n-cnt) * fact(y)) % mod;
        ans = (ans * modInv(fact(y-cnt))) % mod;
        cout << ans << endl;
    }
    return 0;
}