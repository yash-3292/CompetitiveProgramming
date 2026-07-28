#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(vector<ll>& arr, vector<vector<ll>>& o, vector<vector<ll>>& e){
    ll n = arr.size();
    for(ll i=0; i<31; i++){
        ll oddcnt = 0;
        ll evencnt = 1;
        ll cnt = 0;
        for(ll j=0; j<n; j++){
            if(arr[j]&(1<<i)) cnt++;
            if(cnt&1){
                o[i][j] = evencnt;
                e[i][j] = oddcnt;
                oddcnt++;
            } else{
                o[i][j] = oddcnt;
                e[i][j] = evencnt;
                evencnt++;
            }
        }
    }
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<vector<ll>> o1(31,vector<ll>(n)), e1(31,vector<ll>(n)), o2(31,vector<ll>(n)), e2(31,vector<ll>(n));
    f(arr, o1, e1);
    reverse(arr.begin(), arr.end());
    f(arr, o2, e2);
    for(ll i=0; i<31; i++){
        reverse(o2[i].begin(), o2[i].end());
        reverse(e2[i].begin(), e2[i].end());
    }
    reverse(arr.begin(), arr.end());
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ll ind = 0;
        for(ll j=30; j>=0; j--){
            if(arr[i]&(1<<j)){
                ind = j;
                break;
            }
        }
        if(i == 0) ans += e2[ind][i];
        else{
            ans += (e1[ind][i-1]+1) * e2[ind][i];
            ans += o1[ind][i-1] * o2[ind][i];
        }
    }
    cout << ans << endl;
    // ll ans = 0;
    // for(ll j=0; j<n; j++){
    //     ll val = 0;
    //     for(ll i=0; i<=j; i++){
    //         for(ll k=j; k<n; k++){
    //             ll xorr = 0;
    //             for(ll t=i; t<=k; t++){
    //                 xorr = (arr[t]^xorr);
    //             }
    //             if((xorr ^ arr[j]) > xorr){
    //                 if(j == 1) cout << i << " " << k << endl;
    //                 val++;
    //             }
    //         }
    //     }
    //     // cout << val << " ";
    //     ans += val;
    // }
    // cout << endl;
    // cout << ans << endl;
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