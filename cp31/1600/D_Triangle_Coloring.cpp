#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll binpow(ll a, ll b){
    a = a%mod;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

ll inverse(ll x){
    ll ans = binpow(x, mod-2);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    ll num = 1;
    ll den = 1;
    int x = n/3;
    for(int i=1; i<=x; i++) num = (num*(ll)i)%mod;
    for(int i=1; i<=x/2; i++) den = (den*(ll)i)%mod;
    for(int i=1; i<=x/2; i++) den = (den*(ll)i)%mod;
    ll ans = inverse(den);
    ans = (ans*num)%mod;
    for(int i=0; i<n; i+=3){
        int mini = min(arr[i], min(arr[i+1], arr[i+2]));
        ll cnt = 0;
        if(arr[i] == mini) cnt++;
        if(arr[i+1] == mini) cnt++;
        if(arr[i+2] == mini) cnt++;
        if(cnt > 1) ans = (ans*cnt)%mod;
    }
    cout << ans << endl;
    return 0;
}