#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll sum = 0;
    for(ll i=0; i<n; i++) sum += arr[i];
    if(sum*k < x){
        cout << 0 << endl;
        return;
    }
    ll cnt = x/sum;
    if(x%sum == 0) cnt--;
    x -= cnt*sum;
    cnt = cnt * n;
    for(ll i=n-1; i>=0; i--){
        if(arr[i] >= x){
            break;
        } else{
            x -= arr[i];
            cnt++;
        }
    }
    ll ans = n*k - cnt;
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