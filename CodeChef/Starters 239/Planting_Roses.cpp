#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll ans = 0;
    vector<ll> temp(n);
    ll cnt = 0;
    for(ll i=0; i<n; i++){
        cnt += (arr[i] / k);
        arr[i] = arr[i] % k;
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    if(cnt > m/(k+1)){
        ans += (m/(k+1)) * k;
        m = m % (k+1);
        ans += m;
        m = 0;
    } else{
        ans += cnt * k;
        m -= cnt*(k+1);
    }
    for(int i=0; i<n; i++){
        if(m == 0) break;
        if(m <= arr[i]){
            ans += m;
            m = 0;
        } else{
            m -= arr[i]+1;
            ans += arr[i];
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