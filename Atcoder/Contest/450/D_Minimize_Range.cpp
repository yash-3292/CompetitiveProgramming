#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    for(ll i=0; i<n; i++) arr[i] = (arr[i]%k);
    sort(arr.begin(), arr.end());
    ll ans = arr[n-1] - arr[0];
    for(ll i=1; i<n; i++){
        ll val = arr[i-1]+k-arr[i];
        ans = min(ans, val);
    }
    cout << ans << endl;
    return 0;
}