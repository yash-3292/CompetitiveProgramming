#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<ll> preSum(n);
    preSum[0] = arr[0];
    for(ll i=1; i<n; i++){
        preSum[i] = preSum[i-1] + arr[i];
    }
    for(ll i=0; i<n; i++){
        preSum[i] /= (i+1);
    }
    for(ll i=1; i<n; i++){
        preSum[i] = min(preSum[i], preSum[i-1]);
    }
    for(auto it : preSum) cout << it << " ";
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