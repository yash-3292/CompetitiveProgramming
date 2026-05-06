#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        ll x = 1;
        for(int i=n-2; i>=0; i--){
            ll gcd = __gcd(arr[i], arr[i+1]);
            ll mul = arr[i]/gcd;
            arr[i] = gcd;
            if(mul != 1){
                ll lcm = x * mul;
                lcm /= __gcd(x, mul);
                x = lcm;
            }
        }
        cout << x << endl;
    }
    return 0;
}