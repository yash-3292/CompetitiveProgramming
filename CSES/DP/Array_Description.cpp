#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<ll> next(m+1);
    vector<ll> cur(m+1);

    for(int val=1; val<=m; val++){
        if(arr[n-1] != 0 && arr[n-1] != val) next[val] = 0;
        else next[val] = 1;
    }

    for(int i=n-2; i>=0; i--){
        for(int val=1; val<=m; val++){
            if(arr[i] != 0 && arr[i] != val){
                cur[val] = 0;
                continue;
            }
            ll ans1 = 0;
            ll ans2 = 0;
            ll ans3 = 0;
            if(val != 1) ans1 = next[val-1];
            if(val != m) ans2 = next[val+1];
            ans3 = next[val];
            ll ans = (ans1 + ans2) % mod;
            ans = (ans + ans3) % mod;
            cur[val] = ans;
        }
        next = cur;
    }
    ll ans = 0;
    for(int val=1; val<=m; val++){
        ans = (ans + next[val]) % mod;
    }
    cout << ans << "\n";
    return 0;
}