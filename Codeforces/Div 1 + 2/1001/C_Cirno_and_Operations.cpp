#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll ans = LLONG_MIN;
    while(arr.size() >= 1){
        ll sum = 0;
        for(ll i=0; i<arr.size(); i++) sum += arr[i];
        if(arr.size() == n) ans = max(ans, sum);
        else ans = max(ans, abs(sum));
        if(arr.size() == 1) break;
        vector<ll> temp;
        for(ll i=1; i<arr.size(); i++) temp.push_back(arr[i]-arr[i-1]);
        arr = temp;
    }
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