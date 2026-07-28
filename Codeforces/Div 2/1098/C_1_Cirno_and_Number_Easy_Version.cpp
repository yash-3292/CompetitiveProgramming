#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll a, n;
    cin >> a >> n;
    ll x, y;
    cin >> x >> y;
    vector<ll> arr;
    ll temp = a;
    while(temp > 0){
        ll d = temp % 10;
        arr.push_back(d);
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
                val1 = val1*10 + y;
                continue;
            }
            if(j < i){
                if(it == x){
                    val1 = val1*10+x;
                    continue;
                }
                if(it == y){
                    val1 = val1*10+y;
                    continue;
                }
            }
            if(x < it && y < it){
                val1 = val1*10+y;
            } else if(x < it){
                val1 = val1*10+x;
            } else if(y < it){
                val1 = val1*10+y;
            } else{
                val1 = val1*10+x;
            }
            flag = 1;
        }
        ll val2 = 0;
        flag = 0;
        for(ll j=0; j<k; j++){
            ll it = arr[j];
            if(flag){
                val2 = val2*10 + x;
                continue;
            }
            if(j < i){
                if(it == x){
                    val2 = val2*10+x;
                    continue;
                }
                if(it == y){
                    val2 = val2*10+y;
                    continue;
                }
            }
            if(x > it && y > it){
                val2 = val2*10+x;
            } else if(x > it){
                val2 = val2*10+x;
            } else if(y > it){
                val2 = val2*10+y;
            } else{
                val2 = val2*10+x;
            }
            flag = 1;
        }
        ll mini1 = min(abs(a-val1), abs(a-val2));
        mini = min(mini, mini1);
    }
    if(arr.size() >= 2){
        ll val3 = 0;
        for(int i=0; i<arr.size()-1; i++) val3 = val3*10 + y;
        mini = min(mini, abs(a-val3));
    }
    ll val4 = (x != 0) ? x : y;
    for(int i=0; i<arr.size(); i++) val4 = val4*10 + x;
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