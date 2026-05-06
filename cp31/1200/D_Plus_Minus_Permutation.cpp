#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sumNumber(ll n){
    ll sum = (n * (n+1)) / 2;
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;
        ll a = n / x;
        ll b = n / y;
        ll lcm = (x * y) / __gcd(x, y);
        ll c = n / lcm;
        a -= c;
        b -= c;
        ll sum1 = sumNumber(n) - sumNumber(n-a);
        ll sum2 = sumNumber(b);
        ll sum = sum1 - sum2;
        cout << sum << endl;
    }
    return 0;
}