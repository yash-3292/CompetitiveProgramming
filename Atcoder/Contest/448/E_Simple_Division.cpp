#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll k, m;
    cin >> k >> m;
    ll ans = 0;
    ll rm = 0;
    ll r10007 = 0;
    for(int i=0; i<k; i++){
        ll c, l;
        cin >> c >> l;
        for(ll j=0; j<l; j++){
            rm = rm*10 + c;
            r10007 = r10007*10 + rm/m;
            rm %= m;
            r10007 %= 10007;
        }
    }
    cout << r10007 << endl;
    return 0;
}