#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    vector<ll> preSum(n);
    ll a = -1, b = -1;
    for(ll i=0; i<n; i++){
        if(i == 0) preSum[i] = 0;
        else preSum[i] = preSum[i-1];
        if(s[i] == 'L'){
            preSum[i]--;
        } else{
            preSum[i]++;
        }
        if(preSum[i] == -1*x){
            if(a == -1) a = i+1;
        }
        if(preSum[i] == 0){
            if(b == -1) b = i+1;
        }
    }
    if(a == -1){
        cout << 0 << endl;
        return;
    }
    if(k < a){
        cout << 0 << endl;
        return;
    }
    ll ans = 1;
    k -= a;
    if(b == -1){
        cout << ans << endl;
        return;
    }
    ans += k / b;
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