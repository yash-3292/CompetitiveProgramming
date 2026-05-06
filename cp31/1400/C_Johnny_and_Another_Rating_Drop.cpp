#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll val = 1;
        ll ans = 0;
        while(val <= n){
            ans += n/val;
            val *= (ll)2;
        }
        cout << ans << endl;
    }
    return 0;
}