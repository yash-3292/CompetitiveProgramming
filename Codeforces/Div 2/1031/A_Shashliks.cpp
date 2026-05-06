#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        if(x <= y){
            ll ans = 0;
            if(k >= a){
                ll val = (ll)floor(((double)(k-a) / (double)x) + (double)1);
                k -= val * x;
                ans += val;
            }
            if(k >= b){
                ll val = (ll)floor(((double)(k-b) / (double)y) + (double)1);
                k -= val * y;
                ans += val;
            }
            cout << ans << endl;
        } else{
            ll ans = 0;
            if(k >= b){
                ll val = (ll)floor(((double)(k-b) / (double)y) + (double)1);
                k -= val * y;
                ans += val;
            }
            if(k >= a){
                ll val = (ll)floor(((double)(k-a) / (double)x) + (double)1);
                k -= val * x;
                ans += val;
            }
            cout << ans << endl;   
        }
    }
    return 0;
}