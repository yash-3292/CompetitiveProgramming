#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

struct Fraction {
    ll num, den;
};

Fraction reduce(ll a, ll b){
    ll g = __gcd(a, b);

    a /= g;
    b /= g;

    if(b < 0){
        a = -a;
        b = -b;
    }

    return {a, b};
}

bool comp(const Fraction &x, const Fraction &y){
    return (128t)x.num * y.den < (__uint128_t)y.num * x.den;
}

ll binpow(ll a, ll b) {
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a){
    return binpow(a, mod-2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<double> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<Fraction> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j) arr.push_back(reduce(b[j],b[i]));
            }
        }
        sort(arr.begin(), arr.end(), comp);
        ll ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                Fraction x = reduce(a[i],a[j]);
                ll ind = upper_bound(arr.begin(), arr.end(), x, comp) - arr.begin();
                ans = (ans + ind) % mod;
            }
        }
        ll den = (n * (n-1)) % mod;
        ans = ans * inv(den);
        cout << ans << endl;
        // cout << endl;
    }
    return 0;
}