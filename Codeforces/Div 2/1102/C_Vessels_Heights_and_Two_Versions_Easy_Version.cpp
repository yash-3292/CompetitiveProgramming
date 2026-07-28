#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll ind, vector<ll>& h){
    ll n = h.size();
    vector<ll> arr;
    for(ll i=ind; i<n; i++) arr.push_back(h[i]);
    for(ll i=0; i<ind; i++) arr.push_back(h[i]);
    vector<ll> preMax(n), sufMax(n);
    preMax[0] = arr[0];
    for(ll i=1; i<n; i++) preMax[i] = max(preMax[i-1], arr[i]);
    sufMax[n-1] = arr[n-1];
    for(ll i=n-2; i>=0; i--) sufMax[i] = max(sufMax[i+1], arr[i]);
    ll ans = 0;
    for(ll i=0; i<n-1; i++){
        ans += min(preMax[i], sufMax[i+1]);
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> h(n);
    for(ll i=0; i<n; i++) cin >> h[i];
    for(ll i=0; i<n; i++){
        cout << f(i, h) << " ";
    }
    cout << endl;
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