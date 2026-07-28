#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll a, n;
    cin >> a >> n;
    vector<ll> d(n);
    for(ll i=0; i<n; i++) cin >> d[i];
    vector<ll> arr;
    ll temp = a;
    while(temp > 0){
        ll dig = temp % 10;
        arr.push_back(dig);
        temp /= 10;
    }
    reverse(arr.begin(), arr.end());
    if(arr.empty()) arr.push_back(0);
    ll k = arr.size();
    ll mini = 1e18;
    for(ll i=0; i<=k; i++){
        ll val1 = 0;
        int flag = 0;
        for(ll j=0; j<k; j++){
            ll it = arr[j];
            if(flag){
                val1 = val1*10 + d[n-1];
                continue;
            }
            if(j < i){
                int ind = lower_bound(d.begin(), d.end(), it) - d.begin();
                if(ind != n && d[ind] == it){
                    val1 = val1*10 + d[ind];
                    continue;
                } 
            }
            int ind = lower_bound(d.begin(), d.end(), it) - d.begin();
            if(ind != 0){
                ind--;
                val1 = val1*10+d[ind];
            } else{
                val1 = val1*10+d[0];
            }
            flag = 1;
        }
        ll val2 = 0;
        flag = 0;
        for(ll j=0; j<k; j++){
            ll it = arr[j];
            if(flag){
                val2 = val2*10 + d[0];
                continue;
            }
            if(j < i){
                int ind = lower_bound(d.begin(), d.end(), it) - d.begin();
                if(ind != n && d[ind] == it){
                    val2 = val2*10 + d[ind];
                    continue;
                } 
            }
            int ind = upper_bound(d.begin(), d.end(), it) - d.begin();
            if(ind != n){
                val2 = val2*10+d[ind];
            } else{
                val2 = val2*10+d[0];
            }
            flag = 1;
        }
        ll mini1 = min(abs(a-val1), abs(a-val2));
        mini = min(mini, mini1);
    }
    if(arr.size() >= 2){
        ll val3 = 0;
        for(int i=0; i<arr.size()-1; i++) val3 = val3*10 + d[n-1];
        mini = min(mini, abs(a-val3));
    }
    ll val4;
    if(n == 1) val4 = d[0];
    else val4 = (d[0] != 0) ? d[0] : d[1];
    for(int i=0; i<arr.size(); i++) val4 = val4*10 + d[0];
    mini = min(mini, abs(a-val4));
    cout << mini << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}