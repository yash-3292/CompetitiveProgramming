#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> b(n), d(n);
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++) cin >> d[i];

        ll ans = LLONG_MAX;
        for(int r=0; r<n; r++){
            ll val = 0;
            map<int,int> mpp;
            for(int j=-1*r; j<=0; j++){
                mpp[b[(j+n)%n]]++;
            }
            int i = -1*r;
            int j = 0;
            while(j < n){
                val += (ll)d[j] * (ll)(mpp.begin()->first);
                mpp[b[(i+n)%n]]--;
                if(mpp[b[(i+n)%n]] == 0) mpp.erase(b[(i+n)%n]);
                i++;
                j++;
                mpp[b[(j+n)%n]]++;
            }
            val += (ll)r * (ll)c;
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}