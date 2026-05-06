#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        vector<ll> prefa(n);
        vector<ll> sufa(n);
        vector<ll> prefb(n);
        vector<ll> sufb(n);
        prefa[0] = (ll)a[0];
        for(int i=1; i<n; i++){
            ll val = (prefa[i-1] > 0) ? prefa[i-1] : 0;
            val += (ll)a[i];
            prefa[i] = val;
        }
        prefb[0] = (ll)b[0];
        for(int i=1; i<n; i++){
            ll val = (prefb[i-1] > 0) ? prefb[i-1] : 0;
            val += (ll)b[i];
            prefb[i] = val;
        }
        sufa[n-1] = (ll)a[n-1];
        for(int i=n-2; i>=0; i--){
            ll val = (sufa[i+1] > 0) ? sufa[i+1] : 0;
            val += (ll)a[i];
            sufa[i] = val;
        }
        sufb[n-1] = (ll)b[n-1];
        for(int i=n-2; i>=0; i--){
            ll val = (sufb[i+1] > 0) ? sufb[i+1] : 0;
            val += (ll)b[i];
            sufb[i] = val;
        }
        ll maxi = LLONG_MIN;
        for(int i=0; i<n; i++){
            ll val = prefa[i] + sufa[i] - (ll)a[i];
            val += prefb[i] + sufb[i] - (ll)b[i];
            maxi = max(maxi, val);
        }
        cout << maxi << endl;
    }
    return 0;
}