#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll pw(ll a, ll b){
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;

    while(n--){
        int l, r;
        cin >> l >> r;
        int p, q;
        cin >> p >> q; 
    }
    return 0;
}