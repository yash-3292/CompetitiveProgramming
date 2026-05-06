#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m, h;
        cin >> n >> m >> h;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        vector<ll> b(m), c(m);
        for(ll i=0; i<m; i++){
            cin >> b[i] >> c[i];
            b[i]--;
        }
        ll begin = 0;
        while(begin < m){
            ll i = begin;
            while(i < m){
                a[b[i]] += c[i];
                if(a[b[i]] > h) break;
                i++;
            }
            if(i == m) break;
            for(ll j=begin; j<=i; j++){
                a[b[j]] -= c[j];
            }
            begin = i+1;
        }
        for(auto it : a) cout << it << " ";
        cout << endl;
    }
    return 0;
}