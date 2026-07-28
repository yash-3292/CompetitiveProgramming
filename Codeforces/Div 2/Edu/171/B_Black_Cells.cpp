#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll mini = 1e18;
    if(arr.size() == 1){
        cout << 1 << endl;
        return;
    }
    if(n&1){
        for(ll i=0; i<n; i++){
            vector<ll> temp;
            for(ll j=0; j<n; j++) if(i != j) temp.push_back(arr[j]);
            ll maxi = 1;
            for(ll j=1; j<n-1; j+=2){
                maxi = max(maxi, temp[j]-temp[j-1]);
            }
            mini = min(mini, maxi);
        }
    } else{
        ll maxi = 1;
        for(ll i=1; i<n; i+=2){
            maxi = max(maxi, arr[i]-arr[i-1]);
        }
        mini = min(mini, maxi);
    }
    cout << mini << endl;
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