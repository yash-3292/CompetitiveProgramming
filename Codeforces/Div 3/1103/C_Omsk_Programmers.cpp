#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll a, b, x;
    cin >> a >> b >> x;
    ll cnt = 0;
    ll ans = abs(a-b);
    while(a != b){
        ans = min(ans, cnt+abs(a-b));
        if(a > b){
            a /= x;
        } else{
            b /= x;
        }
        cnt++;
    }
    ans = min(ans, cnt);
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