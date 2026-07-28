#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll k, vector<ll>& arr){
    ll n = arr.size();
    vector<ll> ans(n+1,0);
    ans[n] = 0;
    ll sum = 0;
    map<ll,ll> mpp;
    mpp[0]++;
    ll i = n-1;
    for(ll j=n-1; j>=0; j--){
        if(mpp.empty()) return false;
        ans[j] = mpp.begin()->first + arr[j];
        mpp[ans[j]]++;
        sum += arr[j];
        while(sum > k){
            mpp[ans[i+1]]--;
            if(mpp[ans[i+1]] == 0){
                mpp.erase(ans[i+1]);
            }
            sum -= arr[i];
            i--;
        }
    }
    if(mpp.empty()) return false;
    ll val = ans[i];
    val = min(val, mpp.begin()->first);
    return val <= k;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll maxi = 0;
    for(ll i=0; i<n; i++) maxi = max(maxi, arr[i]);
    ll l = maxi;
    ll r = 1e15;
    ll ans = 1e15;
    while(l <= r){
        ll mid = l + (r-l)/2;
        if(check(mid, arr)){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
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