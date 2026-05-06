#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(ll n, ll m, ll a, ll b){
    ll val = (m*a) % n;
    if(val == 0) val = n;
    if(__gcd(val, n) == 1) return true;
    else if(__gcd(val, n) == 2 && (a&1)) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        int flag = 1;
        if(__gcd(n,a) != 1) flag = 0;
        if(__gcd(m,b) != 1) flag = 0;
        if(!(f(n,m,a,b) || f(m,n,b,a))) flag = 0;
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}