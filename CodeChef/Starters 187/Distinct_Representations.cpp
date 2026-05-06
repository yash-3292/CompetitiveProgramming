#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

ll _pow(ll a, ll b){
    if(b == 0) return 1;
    if(b&1){
        ll power = _pow(a, (b-1)/2);
        return ((a%mod) * power * power) % mod;
    } 
    else{
        ll power = _pow(a, b/2);
        return (power * power)%mod;
    }
}

ll total_Case(ll n){
    ll cases = 1;
    ll num = (n-1)/3;
    cases = (cases + _pow(2,num)-1)%mod;
    num = (n-2)/3;
    cases = (cases + _pow(2,num)-1)%mod;
    num = (n-3)/3;
    cases = (cases + _pow(2,num)-1)%mod;
    return cases;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll prob = 1;
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1]){
                cnt++;
            } else{
                ll cases = total_Case((ll)cnt);
                prob = (prob * cases) % mod;
                cnt = 1;
            }
        }
        if(cnt != 1){
            ll cases = total_Case((ll)cnt);
            prob = (prob * cases) % mod;
            cnt = 1;
        }
        cout << prob << endl;
    }
    return 0;
}