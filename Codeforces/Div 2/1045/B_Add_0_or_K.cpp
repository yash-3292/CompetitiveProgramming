#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    for(ll i=0; i<n; i++){
        arr[i] = arr[i] + (arr[i]%(k+1)) * k;
        cout << arr[i] << " ";
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