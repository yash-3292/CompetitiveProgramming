#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll x, y, k;
        cin >> x >> y >> k;
        ll l = 1;
        ll r =  1e12;
        ll ans = -1;
        while(l <= r){
            ll mid = l + (r-l)/2;
            ll pos = mid;
            for(int i=0; i<x; i++) pos -= pos/y;
            if(pos == k){
                ans = mid;
                r = mid-1;
            } else if(pos > k){
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}