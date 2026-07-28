#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll x = 0, y = 0;
    ll n1 = 0, n2 = 0;
    for(ll i=1; i<30; i+=2){
        n1 = (n1 | (1LL << i));
    }
    for(ll i=0; i<30; i+=2){
        n2 = (n2 | (1LL << i));
    }

    cout << n1 << "\n";
    cout << flush;
    ll sum1;
    cin >> sum1;
    sum1 -= 2*n1;
    for(ll i=0; i<30; i+=2){
        bool c = false, n = false;
        if(sum1 & (1LL << i)) c = true;
        if(sum1 & (1LL << (i+1))) n = true;
        if(n){
            x = (x | (1LL << i));
            y = (y | (1LL << i));
        } else if(c){
            x = (x | (1LL << i));
        }
    }

    cout << n2 << "\n";
    cout << flush;
    ll sum2;
    cin >> sum2;
    sum2 -= 2*n2;
    for(ll i=1; i<30; i+=2){
        bool c = false, n = false;
        if(sum2 & (1LL << i)) c = true;
        if(sum2 & (1LL << (i+1))) n = true;
        if(n){
            x = (x | (1LL << i));
            y = (y | (1LL << i));
        } else if(c){
            x = (x | (1LL << i));
        }
    }

    cout << "!\n";
    cout << flush;
    ll m;
    cin >> m;
    ll ans = (m | x) + (m | y);
    cout << ans << "\n";
    cout << flush;
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