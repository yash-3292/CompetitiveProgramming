#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        ll x;
        cin >> n >> x;
        ll maxi = 0;
        for(int i=0; i<n; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            x -= a*(b-1);
            ll val = a*b - c;
            maxi = max(maxi, val);
        }
        if(x <= 0){
            cout << 0 << endl;
            continue;
        }
        if(maxi <= 0){
            cout << -1 << endl;
            continue;
        }
        ll ans;
        if(x%maxi == 0){
            ans = x/maxi;
        } else{
            ans = x/maxi+1;
        }
        cout << ans << endl;
    }
    return 0;
}