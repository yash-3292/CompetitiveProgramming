#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll ans = 0;
    ll g1 = 0, g2 = 0, g3 = 0;
    ll maxi = 0;
    for(ll i=0; i<n; i++){
        if(arr[i] >= 3) ans = max(ans, arr[i]);
        if(arr[i] >= 3) g3 = 1;
        else if(arr[i] >= 2) g2 = 1;
        else if(arr[i] >= 1) g1 = 1;
        maxi = max(maxi, arr[i]);
    }
    if(g3 && g1) ans = max(ans, (ll)4);
    if(g2 && g1) ans = max(ans, (ll)3);
    ll val = 0;
    ll single = 0;
    ll slot = 0;
    for(ll i=0; i<n; i++){
        if(arr[i] == 1){
            single++;
            continue;
        } 
        val += arr[i];
        slot += (arr[i]/2) - 1;
    }
    val += min(single, slot);
    ans = max(ans, val);
    if(maxi >= 2){
        ll val1 = maxi;
        val1 += min(single, maxi/2);
        ans = max(ans, val1);
    }
    if(ans < 3) ans = 0;
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