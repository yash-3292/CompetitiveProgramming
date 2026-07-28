#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<ll> sufSum(n);
    sufSum[n-1] = arr[n-1];
    for(ll i=n-2; i>=0; i--){
        sufSum[i] = sufSum[i+1] + arr[i];
    }
    vector<ll> ans(n);
    vector<pair<ll,ll>> temp;
    for(ll i=0; i<n; i++){
        temp.push_back({sufSum[i],i});
    }
    sort(temp.begin(), temp.end());
    for(ll i=0; i<n; i++){
        ans[temp[i].second] = i+1;
    }
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