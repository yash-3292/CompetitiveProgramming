#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];
    vector<ll> freq(m+1, 0);
    for(ll i=0; i<n; i++){
        freq[a[i]]++;
    }
    vector<vector<ll>> arr;
    for(ll i=1; i<=m; i++){
        arr[freq[i]].push_back(i);
    }
    ll q;
    cin >> q;
    vector<pair<ll,ll>> query(q);
    for(ll i=0; i<q; i++){
        cin >> query[i].first;
        query[i].second = i;
    }
    sort(query.begin(), query.end());
    vector<ll> ans(q);
    
    // for(auto it : ans){
    //     cout << it << endl;
    // }
    return 0;
}