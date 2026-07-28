#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n){
    if(n <= 2) return 0;
    ll odd = (n-1)/2;
    ll ans = odd * n - ((odd+1) * (odd+1) - 1) + odd;
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> arr(3, 0);
    ll val = 0;
    arr[0] = 1;
    ll ans = 0;
    for(ll i=0; i<n; i++){
        if(s[i] == '0'){
            val = (val - 1 + 3) % 3;
        } else{
            val = (val + 1) % 3;
        }
        ans += arr[val];
        arr[val]++;
    }
    ll cnt = 0;
    for(ll i=0; i<n; i++){
        if(i > 0 && s[i] == s[i-1]){
            ans += f(cnt);
            cnt = 1;
        } else{
            cnt++;
        }
    }
    ans += f(cnt);
    ans = (n * (n+1))/2 - ans;
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