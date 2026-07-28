#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

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

void solve(){
    ll n, k;
    cin >> n >> k;
    if(k >= n){
        cout << binpow(2,n) << endl;
        return;  
    }
    cout << "coming soon" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}