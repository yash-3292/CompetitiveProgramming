#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    l--;
    r--;
    vector<ll> arr1, arr2, arr3;
    for(ll i=0; i<n; i++){
        if(i < l){
            arr1.push_back(arr[i]);
        } else if(l <= i && i <= r){
            arr2.push_back(arr[i]);
        } else{
            arr3.push_back(arr[i]);
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<ll>());
    sort(arr3.begin(), arr3.end());
    ll sum = 0;
    for(auto it : arr2) sum += it;
    ll ans = sum;
    for(ll i=1; i<arr1.size(); i++){
        arr1[i] += arr1[i-1];
    }
    for(ll i=1; i<arr2.size(); i++){
        arr2[i] += arr2[i-1];
    }
    for(ll i=1; i<arr3.size(); i++){
        arr3[i] += arr3[i-1];
    }
    for(ll i=0; i<min(arr1.size(), arr2.size()); i++){
        ans = min(ans, sum-arr2[i]+arr1[i]);
    }
    for(ll i=0; i<min(arr3.size(), arr2.size()); i++){
        ans = min(ans, sum-arr2[i]+arr3[i]);
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