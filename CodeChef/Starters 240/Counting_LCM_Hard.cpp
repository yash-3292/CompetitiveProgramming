#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1e6+10;
ll spf[MAXN];

void sieve() {
    for (ll i = 1; i < MAXN; i++) spf[i] = i;
    
    for (ll i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

ll f(ll x){
    ll cnt = 0;
    while(x != 1){
        ll d = spf[x];
        cnt++;
        while(x%d == 0) x /= d;
    }
    return cnt;
}

void solve(){
    ll z;
    cin >> z;
    vector<ll> arr(z+1);
    for(ll i=1; i<=z; i++){
        arr[i] = f(i);
        arr[i] = (1LL<<arr[i]);
        if(i > 1) arr[i] += arr[i-1];
    }
    ll ans = 0;
    for(ll i=1; i<=z; i++){
        ans += arr[z/i];
    }
    ans = z*z - ans;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}