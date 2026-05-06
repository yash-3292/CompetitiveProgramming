#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans;
        if(b%a == 0){
            ans = (b*b)/a;
        } else{
            ans = (a*b)/__gcd(a,b);
        }
        cout << ans << endl;
    }
    return 0;
}