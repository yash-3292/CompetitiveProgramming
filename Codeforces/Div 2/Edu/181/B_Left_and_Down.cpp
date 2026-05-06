#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, k;
        cin >> a >> b >> k;
        ll gcd = __gcd(a, b);
        ll val1 = a/gcd;
        ll val2 = b/gcd;
        if(val1 <= k && val2 <= k){
            cout << 1 << endl;
        } else{
            cout << 2 << endl;
        }
    }
    return 0;
}