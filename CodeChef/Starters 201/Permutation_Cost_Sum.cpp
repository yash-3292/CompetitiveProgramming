#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int j = i;
                int cnt = 0;
                while(!vis[j]){
                    cnt++;
                    vis[j] = 1;
                    j = arr[j]-1;
                }
                if(cnt > 1){
                    for(int x=1; x<=n; x++){
                        for(int y=1; y<=n; y++){
                            ll val1 = (ll)cnt*(ll)x;
                            ll val2 = (ll)(cnt-1)*(ll)y;
                            ans += min(val1, val2);
                            ans %= mod;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}