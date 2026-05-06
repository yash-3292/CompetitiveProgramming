#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll m = 1e9 + 7;

ll binExp(ll a, ll b){
    if(b == 0) return 1;
    if(b&1){
        ll t = binExp(a, (b-1)/2);
        t = (t*t)%m;
        return (a%m * t)%m;
    } else{
        ll t = binExp(a, b/2);
        t = (t*t)%m;
        return t;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll ans = binExp(n, k);
        cout << ans << endl;
    }
    return 0;
}