#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m; 
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<ll> b(m);
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    if(a[0] == a[n-1]){
        for(int i=0; i<m; i++){
            ll val = b[i] + a[0];
            cout << val << " ";
        }
        cout << endl;
        return 0;
    }
    ll gcd = -1;
    for(int i=1; i<n; i++){
        if(a[i] != a[i-1]){
            ll diff = a[i] - a[i-1];
            if(gcd == -1) gcd = diff;
            else gcd = __gcd(gcd, diff);
        }
    }
    ll base = a[0]%gcd;
    for(int i=0; i<m; i++){
        ll ans = __gcd(base+b[i], gcd);
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}