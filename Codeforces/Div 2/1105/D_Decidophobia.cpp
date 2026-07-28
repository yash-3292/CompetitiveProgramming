#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, d;
    cin >> n >> d;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<ll> sum(n);
    vector<ll> temp;
    for(ll i=0; i<3; i++){
        for(auto it : arr) temp.push_back(it);
    }
    ll i = 0;
    ll j = 0;
    ll val = 0;
    while(j < temp.size()){
        val += temp[j];
        if(j-i+1 > d){
            val -= temp[i];
            i++;
        }
        if(n <= j+1 && j+1 < 2*n){
            sum[j+1 - n] += val;
        }
        j++;
    }
    reverse(temp.begin(), temp.end());
    i = 0;
    j = 0;
    val = 0;
    while(j < temp.size()){
        val += temp[j];
        if(j-i+1 > d){
            val -= temp[i];
            i++;
        }
        if(n <= j+1 && j+1 < 2*n){
            sum[n - (j+1 - n) - 1] += val;
        }
        j++;
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += max(0LL, 2*d*arr[i] - sum[i]);
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