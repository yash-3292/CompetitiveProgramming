#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, c, k;
        cin >> n >> c >> k;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for(ll i=0; i<n; i++){
            if(arr[i] > c){
                break;
            }
            ll val = c-arr[i];
            val = min(val, k);
            k -= val;
            c += arr[i]+val;
        }
        cout << c << endl;
    }
    return 0;
}