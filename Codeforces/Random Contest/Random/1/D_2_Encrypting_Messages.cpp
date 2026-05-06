#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m; 
    ll c;
    cin >> n >> m >> c;
    vector<ll> a(n);
    vector<ll> b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    for(int i=1; i<m; i++){
        b[i] = b[i] + b[i-1];
    }
    
    for(int i=0; i<n; i++){
        int r = min(m-1, i);
        int l = max(0, i-(n-m));
        ll ans = b[r];
        if(l != 0) ans -= b[l-1];
        ans += a[i];
        ans = ans%c;
        cout << ans << " "; 
    }
    cout << endl;
    return 0;
}