#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n+1);
    for(ll i=1; i<=n; i++) cin >> arr[i];
    arr[0] = 0;
    vector<ll> preSum(n+1);
    preSum[0] = arr[0];
    for(ll i=1; i<=n; i++) preSum[i] = preSum[i-1] + arr[i];
    vector<ll> preAbsSum(n+1);
    preAbsSum[0] = abs(arr[0]);
    for(ll i=1; i<=n; i++) preAbsSum[i] = preAbsSum[i-1] + abs(arr[i]);
    vector<ll> extra(n+1, 0);
    for(ll i=1; i<=n; i++){
        if(arr[i] > 0){
            ll val = preAbsSum[i-1] - preSum[i-1] - 2 * arr[i];
            if(val > 0){
                extra[i] = val;
            }
        }
    }
    vector<ll> ans;
    ll ind = 0;
    for(ll i=1; i<=n; i++){
        if(extra[i] > extra[ind]){
            ind = i;
        }
    }
    if(ind == 0){
        cout << 0 << endl;
        cout << endl;
        return;
    }
    ll prevmin = -1;
    for(ll i=1; i<ind; i++){
        if(arr[i] > 0){
            if(i+1 < ind && arr[i+1] > 0){
                continue;
            }
            ans.push_back(i);
            if(prevmin != -1) ans.push_back(prevmin);
            prevmin = i;
        } else{
            prevmin = i;
        }
    }
    ans.push_back(ind);
    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
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