#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr;
    while(n > 0){
        ll d = n%10;
        arr.push_back(d);
        n /= 10;
    }
    arr.push_back(0);
    ll sz = arr.size();
    ll cnt = 0;
    ll ans = 10;
    for(ll i=0; i<sz; i++){
        if(i == 0){
            if(arr[i] >= 7){
                ans = min(ans, arr[i] - 7);
            } else{
                ans = min(ans, arr[i] + 3);
            }
            cnt += arr[i];
        } else{
            if(arr[i] == 8){
                ans = min(ans, cnt+1);
            }
            ll diff;
            if(arr[i] > 7){
                diff = 17 - arr[i];
            } else{
                diff = 7 - arr[i];
            }
            if(diff > cnt){
                ans = min(ans, diff+1);
            } else{
                ans = min(ans, diff);
            }
            ll val = arr[i];
            for(ll j=0; j<i; j++) val = val * 10;
            cnt += val;
        }
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