#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res * a) % mod;
        b >>= 1;
        a = (a*a) % mod;
    }
    return res;
}

ll f(int i, int val, int state, vector<int>& arr){
    if(i == arr.size()){
        if(state == 2) return 1;
        return 0;
    }

    ll notTake = f(i+1, val, state, arr);
    ll take = 0;
    if(state == 2){
        take = f(i+1, arr[i], state, arr);
    } else{

    }
    ll ans = (take + notTake) % mod;
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll ans = binpow((ll)2,(ll)n);
    ans -= f(0, 0, 0, arr);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}