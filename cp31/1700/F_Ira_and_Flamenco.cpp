#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll binpow(ll a, ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    ll res = 1;
    while(b > 0){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a){
    return binpow(a, mod-2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> arr;
        map<int,int> freq;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }
        for(auto it : freq) arr.push_back({it.first, it.second});
        n = arr.size();
        ll ans = 0;
        int i = 0;
        int j = 0;
        ll val = 1;
        while(j < n){
            val = (val*arr[j].second)%mod;
            if(j-i+1 > m){
                val = (val*inv((ll)arr[i].second))%mod;
                i++;
            }
            if(j-i+1 == m && arr[j].first-arr[i].first < m){
                ans = (ans + val)%mod;
            }
            j++;
        }
        cout << ans << endl;
    }
    return 0;
}