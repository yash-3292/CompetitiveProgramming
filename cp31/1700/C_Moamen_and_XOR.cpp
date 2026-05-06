#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(b == 0 || a == 1) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a)%mod;
        b >>= 1;
        a = (a*a)%mod;
    }
    return res;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll prev = 1;
        for(int i=1; i<=k; i++){
            ll ans = 0;
            if(n&1){
                ll val = prev;
                val = val * (1 + binpow(2,n-1));
                ans = val%mod;
            } else{
                ll val = prev;
                val = val * (binpow(2,n-1) - 1);
                val = val%mod;
                ans += val;
                ans = ans + binpow(binpow(2,n), i-1);
                ans = ans%mod;
            }
            prev = ans;
        }
        int ans = prev;
        cout << ans << endl;
    }
    return 0;
}