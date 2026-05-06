#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll mid, ll s, vector<ll>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        s -= min(s/arr[i], mid) * arr[i];
    }
    return (s==0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll s, m;
        cin >> s >> m;
        vector<ll> arr;
        for(ll i=60; i>=0; i--){
            if(m&(1LL<<i)){
                arr.push_back(1LL<<i);
            }
        }
        ll l = 1;
        ll r = 1e18;
        ll ans = -1;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(check(mid, s, arr)){
                ans = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}