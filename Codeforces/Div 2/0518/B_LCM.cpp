#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll b;
    cin >> b;
    ll ans = 0;
    for(ll i=1; i*i<=b; i++){
        if(b%i == 0){
            if(i == b/i) ans++;
            else ans += 2; 
        }
    }
    cout << ans << endl;
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