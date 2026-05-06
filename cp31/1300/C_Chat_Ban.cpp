#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k, x;
        cin >> k >> x;
        ll val = (k * (k+1)) / 2;
        if(x < val){
            ll low = 1;
            ll high = k;
            ll ans;
            while(low <= high){
                ll mid = low + (high-low)/2;
                ll sum = (mid * (mid+1)) / 2;
                if(sum <= x){
                    ans = mid;
                    low = mid + 1;
                } else{
                    high = mid - 1;
                }
            }
            ll sum = (ans * (ans+1))/2;
            if(x > sum) ans++;
            cout << ans << endl;
        } else if(x > val){
            if(x >= k * k){
                ll ans = 2*k - 1;
                cout << ans << endl;
                continue;
            }
            ll diff = k*k - x;
            ll low = 1;
            ll high = k-1;
            ll ans;
            while(low <= high){
                ll mid = low + (high-low)/2;
                ll sum = (mid * (mid+1)) / 2;
                if(sum >= diff){
                    ans = mid;
                    high = mid - 1;
                } else{
                    low = mid + 1;
                }
            }
            ll sum = (ans * (ans+1))/2;
            if(sum > diff) ans--;
            ans = 2*k - 1 - ans;
            cout << ans << endl;
        } else{
            cout << k << endl;
        }
    }
    return 0;
}