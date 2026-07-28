#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(2*n);
    for(ll i=0; i<2*n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<ll> ans(2*n+1);
    vector<ll> pos;
    vector<ll> neg;
    for(int i=0; i<2*n; i++){
        if(i < n-1){
            neg.push_back(arr[i]);
        } else{
            pos.push_back(arr[i]);
        }
    }
    ll val = 0;
    for(auto it : pos) val += it;
    for(auto it : neg) val -= it;
    neg.push_back(val);
    for(int i=0; i<=n; i++){
        ans[2*i] = pos[i];
    }
    for(int i=0; i<n; i++){
        ans[2*i+1] = neg[i];
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