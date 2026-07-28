#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(ll val1, ll v2, ll sum, vector<ll>& b, unordered_map<ll,int>& vis){
    ll l = b.size();
    ll i = 0;
    ll j = b.size()-1;
    while(i <= j){
        ll mid = i + (j-i)/2;
        ll x = sum - val1 - v2*b[mid];
        if(x >= -2e5){
            l = mid;
            j = mid-1;
        } else{
            i = mid+1;
        }
    }
    ll r = -1;
    i = 0;
    j = b.size()-1;
    while(i <= j){
        ll mid = i + (j-i)/2;
        ll x = sum - val1 - v2*b[mid];
        if(x <= 2e5){
            r = mid;
            i = mid+1;
        } else{
            j = mid-1;
        }
    }
    for(ll k=l; k<=r; k++){
        ll x = sum - val1 - v2*b[k];
        vis[x] = 1;
    }
}

void solve(){
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n), b(m);
    for(ll i=0; i<n; i++) cin >> a[i];
    for(ll i=0; i<m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll sum1 = 0;
    ll sum2 = 0;
    for(ll i=0; i<n; i++) sum1 += a[i];
    for(ll i=0; i<m; i++) sum2 += b[i];
    ll sum = sum1*sum2;
    vector<ll> au, bu;
    for(ll i=0; i<n; i++) if(i == 0 || a[i] != a[i-1]) au.push_back(a[i]);
    for(ll i=0; i<m; i++) if(i == 0 || b[i] != b[i-1]) bu.push_back(b[i]);
    vector<ll> rbu(bu);
    reverse(rbu.begin(), rbu.end());
    unordered_map<ll,int> vis;
    for(ll i=0; i<au.size(); i++){
        ll val1 = au[i]*sum2;
        ll v2 = sum1-au[i];
        if(sum1-au[i] >= 0){
            f(val1, v2, sum, rbu, vis);
        } else{
            f(val1, v2, sum, bu, vis);
        }
    }
    while(q--){
        ll x;
        cin >> x;
        if(vis.find(x) != vis.end()){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}