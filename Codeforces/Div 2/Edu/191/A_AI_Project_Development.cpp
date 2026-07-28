#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, x, y, z;
    cin >> n >> x >> y >> z;
    ll ans = n / (x+y);
    if(n%(x+y) != 0) ans++;
    ll l = 1;
    ll r = 1e6;
    ll ans1 = -1;
    while(l <= r){
        ll mid = l + (r-l)/2;
        ll val = max(0LL, mid-z) * y * 10;
        val += x * mid;
        if(val >= n){
            ans1 = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    ans = min(ans, ans1);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}