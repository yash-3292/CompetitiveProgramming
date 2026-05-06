#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<int> q(n), r(n);
        for(int i=0; i<n; i++) cin >> q[i];
        for(int i=0; i<n; i++) cin >> r[i];
        sort(q.begin(), q.end());
        sort(r.begin(), r.end());
        int j = n-1; 
        int ans = 0;
        for(int i=0; i<n; i++){
            while(j >= 0){
                ll val = (ll)(r[i] + 1) * (ll)(q[j]) + (ll)r[i];
                if(val <= k){
                    ans++;
                    j--;
                    break;
                }
                j--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}