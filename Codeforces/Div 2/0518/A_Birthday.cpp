#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    ll x = (k+l);
    if(x%m == 0) x /= m;
    else{
        x /= m;
        x++;
    }
    if(m*x > n){
        cout << -1 << endl;
        return;
    }
    cout << x << endl;
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