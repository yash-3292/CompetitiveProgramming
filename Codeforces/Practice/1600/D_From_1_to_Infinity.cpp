#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll n, vector<ll>& a){
    if(n < 10) return (n*(n+1))/2;

    ll d = (ll)log10(n);
    ll p = 1;
    for(int i = 0; i < d; i++) p *= 10;
    ll msd = n / p;

    return (msd * a[d] + ((msd * (msd - 1)) / 2) * p + msd * (1 + n%p) + f(n%p, a));
}

ll sum(ll n){
    ll d = max((ll)(log10(n)), (ll)1);
    vector<ll> a(d+1);
    a[0] = 0;
    a[1] = 45;

    ll p = 1;
    for(int i=2; i<=d; i++){
        p *= 10;
        a[i] = a[i-1] * 10 + 45 * p;
    }

    return f(n, a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        ll rem = k;
        ll n = 0;
        ll p = 1;
        for(ll x=0; x<14; x++){
            ll val = (ll)9 * p * (x+1);
            if(val > rem){
                n += rem/(x+1);
                rem = rem%(x+1);
                break;
            }
            n += (ll)9 * p;
            rem -= val;
            p *= 10;
        }
        ll ans = sum(n);
        ll temp = n+1;
        vector<int> arr;
        while(temp > 0){
            int d = temp%10;
            arr.push_back(d);
            temp /= 10; 
        }
        reverse(arr.begin(), arr.end());
        for(int i=0; i<rem; i++) ans += (ll)arr[i];
        cout << ans << endl;
    }
    return 0;
}