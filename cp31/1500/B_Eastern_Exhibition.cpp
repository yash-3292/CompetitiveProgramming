#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0; i<n; i++) cin >> x[i] >> y[i];
        if(n&1){
            cout << 1 << endl;
            continue;
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll a = (ll)x[n/2] - (ll)x[n/2-1] + 1;
        ll b = (ll)y[n/2] - (ll)y[n/2-1] + 1;
        ll ans = a*b;
        cout << ans << endl;
    }
    return 0;
}