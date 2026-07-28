#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
    vector<pair<ll,ll>> temp;
    for(ll i=0; i<n; i++){
        temp.push_back({arr[i]+i, i});
    }
    unordered_map<ll,ll> vis;
    vis[n] = 1; 
    ll ans = n;
    sort(temp.begin(), temp.end());
    // for(auto it : temp) cout << it.first << " " << it.second << endl;
    for(ll i=0; i<n; i++){
        if(vis.find(temp[i].first) != vis.end()){
            ans = max(ans, temp[i].first);
            vis[temp[i].first+temp[i].second] = 1;
            ans = max(ans, temp[i].first+temp[i].second);
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