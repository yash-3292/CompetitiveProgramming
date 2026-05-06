#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<k; i++) cin >> b[i];
        vector<int> vis(n+1, 0);
        vector<int> mpp(n+1);
        for(int i=0; i<n; i++){
            mpp[a[i]] = i;
        }
        ll ans = 1;
        for(int i=k-1; i>=0; i--){
            int ind = mpp[b[i]];
            int num = 0;
            if(ind > 0 && !vis[a[ind-1]]) num++;
            if(ind<n-1 && !vis[a[ind+1]]) num++;
            if(num == 0){
                ans = 0;
                break;
            } else if(num == 2){
                ans = (ans*2)%mod;
            }
            vis[b[i]] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}