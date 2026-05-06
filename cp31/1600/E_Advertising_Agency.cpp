#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = (ll)(1e9+7);

ll binPow(ll a, ll b){
    ll res = 1;
    a = a%mod;
    while(b > 0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

ll inverse(ll num){
    ll inverse = binPow(num, mod-2);
    return inverse;
}

ll fact(ll n){
    ll ans = 1;
    for(ll i=1; i<=n; i++){
        ans = (ans*i)%mod;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        int m = 0;
        int r = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == arr[k-1]){
                m++;
                if(i <= k-1) r++;
            }
        }
        ll num = fact((ll)m);
        ll den = fact((ll)r);
        den = (den*fact((ll)(m-r)))%mod;
        ll inv = inverse(den);
        num = (num*inv)%mod;
        cout << num << endl;
    }
    return 0;
}