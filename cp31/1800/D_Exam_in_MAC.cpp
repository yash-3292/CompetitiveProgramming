#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        ll ans = ((c+1)*(c+2))/2;
        ll val = 0;
        ll e = 0;
        ll o = 0;
        for(int i=0; i<n; i++){
            ll x;
            cin >> x;
            val += x/2 + 1 + c - x;
            if(x&1) o++;
            else e++;
        }
        val -= ((e)*(e-1))/2;
        val -= ((o)*(o-1))/2;
        ans -= val;
        cout << ans << endl;
    }
    return 0;
}