#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    for(ll i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            ll temp = arr[i] + arr[i+1];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    cout << arr[n-1] << endl;
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