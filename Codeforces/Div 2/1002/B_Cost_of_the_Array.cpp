#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    if(k == n){
        vector<ll> temp;
        for(ll i=1; i<n; i+=2){
            temp.push_back(arr[i]);
        }
        ll sz = temp.size();
        for(ll i=0; i<sz; i++){
            if(i+1 != temp[i]){
                cout << i+1 << endl;
                return;
            }
        }
        cout << sz+1 << endl;
        return;
    }
    if(arr[2] != 1){
        cout << 1 << endl;
        return;
    }
    ll ans = 2;
    ll ind = -1;
    for(ll i=1; i<n; i++){
        if(arr[i] != 1){
            ind = i+1;
            break;
        }
    }
    if(n - ind + 2 >= k && ind != -1){
        ans = 1;
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