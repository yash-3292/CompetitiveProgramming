#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll i, ll k, vector<ll>& arr){
    ll n = arr.size() - 1;
    ll ans = 0;
    for(ll j=i; j<=min(i+1,n); j++){
        ll val1 = (arr[j-1] % k);
        ll val2 = (arr[j] % k);
        if(val1 <= val2){
            ans += abs(val2-val1);
        } else{
            ans += k - abs(val2-val1);
        }
    }
    return ans;
}

void solve(){
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> arr(n+1);
    arr[0] = 0;
    for(ll i=1; i<=n; i++) cin >> arr[i];
    vector<ll> factors;
    for(ll i=1; i*i<=m; i++){
        if(m%i == 0){
            factors.push_back(i);
            if(m/i != i) factors.push_back(m/i);
        }
    }
    unordered_map<ll,ll> mpp;
    for(auto k : factors){
        for(ll i=1; i<=n; i++){
            ll val1 = (arr[i-1] % k);
            ll val2 = (arr[i] % k);
            if(val1 <= val2){
                mpp[k] += abs(val2-val1);
            } else{
                mpp[k] += k - abs(val2-val1);
            }
        }
    }
    while(q--){
        ll o;
        cin >> o;
        if(o == 1){
            ll i, x;
            cin >> i >> x;
            ll prev = arr[i];
            for(auto k : factors){
                mpp[k] -= f(i, k, arr);
                arr[i] = x;
                mpp[k] += f(i, k, arr);
                arr[i] = prev;
            }
            arr[i] = x;
        } else{
            ll k;
            cin >> k;
            k = __gcd(m, k);
            if(mpp[k] < m){
                cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        }
    }
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