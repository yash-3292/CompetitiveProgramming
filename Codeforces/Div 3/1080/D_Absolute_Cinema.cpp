#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> f(n), a(n);
        for(int i=0; i<n; i++) cin >> f[i];
        for(int i=1; i<n-1; i++){
            a[i] = (f[i-1] + f[i+1] - 2*f[i])/2;
        }
        ll val1 = 0;
        for(int i=1; i<n-1; i++){
            val1 += (ll)(i) * a[i];
        }
        a[n-1] = (f[0] - val1) / (ll)(n-1);
        ll val2 = 0;
        for(int i=1; i<n; i++){
            val2 += (ll)abs(i-1) * a[i]; 
        }
        a[0] = f[1] - val2;
        for(auto it : a) cout << it << " ";
        cout << endl;
    }
    return 0;
}