#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll pw(ll a, ll b){
    if(b == 0) return (ll)1;
    if(b % 2 == 0){
        ll t = pw(a, b/2);
        return ((t * t)% mod);
    }
    else{
        ll t = pw(a, (b-1)/2);
        t = (t * t) % mod;
        return ((a * t) % mod);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> p(n);
        vector<ll> q(n);
        for(int i=0; i<n; i++) cin >> p[i];
        for(int i=0; i<n; i++) cin >> q[i];
        vector<int> maxpos1(n);
        vector<int> maxpos2(n);
        maxpos1[0] = 0;
        maxpos2[0] = 0;
        for(int i=1; i<n; i++){
            if(p[i] > p[maxpos1[i-1]]){
                maxpos1[i] = i;
            } else{
                maxpos1[i] = maxpos1[i-1];
            }
        }
        for(int i=1; i<n; i++){
            if(q[i] > q[maxpos2[i-1]]){
                maxpos2[i] = i;
            } else{
                maxpos2[i] = maxpos2[i-1];
            }
        }
        for(int i=0; i<n; i++){
            ll num;
            if(p[maxpos1[i]] > q[maxpos2[i]]){
                num = (pw((ll)2, p[maxpos1[i]]) + pw((ll)2, q[i - maxpos1[i]])) % mod;
            }
            else if(p[maxpos1[i]] < q[maxpos2[i]]){
                num = (pw((ll)2, q[maxpos2[i]]) + pw((ll)2, p[i - maxpos2[i]])) % mod;
            }
            else{
                if(q[i - maxpos1[i]] >= p[i - maxpos2[i]]){
                    num = (pw((ll)2, p[maxpos1[i]]) + pw((ll)2, q[i - maxpos1[i]])) % mod;
                } else{
                    num = (pw((ll)2, q[maxpos2[i]]) + pw((ll)2, p[i - maxpos2[i]])) % mod;
                }
            }
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}