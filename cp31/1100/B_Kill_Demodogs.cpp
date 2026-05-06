#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n; 
        cin >> n;
        ll sum = 0;
        ll val1 = n*(n-1) / 2;
        val1 %= mod;
        ll val2 = n*n;
        val2 %= mod;
        ll val3;
        if(n % 3 == 0){
            val3 = n/3;
            val3 = (val3 * (n-1)) % mod;
            val3 = (val3 * (2*n - 1)) % mod;
        } else if((n-1) % 3 == 0){
            val3 = ((n-1)/3)%mod;
            val3 = (val3 * (n)%mod) % mod;
            val3 = (val3 * (2*n - 1)%mod) % mod;
        } else{
            val3 = ((2*n-1)/3) % mod;
            val3 = (val3 * (n)%mod) % mod;
            val3 = (val3 * (n - 1)%mod) % mod;
        }
        sum = (val1 + val2 + val3) % mod;
        sum = (sum * 2022) % mod;
        cout << sum << endl;
    }
    return 0;
}