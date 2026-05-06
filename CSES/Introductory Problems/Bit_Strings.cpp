#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll const mod = (ll)1000000007;

int main(){
    int n;
    cin >> n;
    ll ans = 1;
    for(int i=0; i<n; i++){
        ans = ans*2 % mod;
    }
    cout << ans << endl;
    return 0;
}