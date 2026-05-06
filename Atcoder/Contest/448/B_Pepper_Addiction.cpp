#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> c(m+1);
    for(ll i=1; i<=m; i++) cin >> c[i];
    vector<ll> pR(m+1, 0);
    for(ll i=0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        pR[a] += b;
    }
    ll sum = 0;
    for(ll i=1; i<=m; i++){
        sum += min(pR[i], c[i]);
    }
    cout << sum << endl;
    return 0;
}