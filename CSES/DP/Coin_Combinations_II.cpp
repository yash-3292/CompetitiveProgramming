#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin >> c[i];
    sort(c.begin(), c.end());
    vector<ll> prev(x+1, 0);
    vector<ll> cur(x+1, 0);
    prev[0] = 1;
    for(int i=n-1; i>=0; i--){
        for(int sum=0; sum<=x; sum++){
            ll ans = 0;
            ll notTake = prev[sum];
            ll take = 0;
            if(sum >= c[i]){
                take = cur[sum-c[i]];
            }
            ans = (take + notTake) % mod;
            cur[sum] = ans;
        }
        prev = cur;
    }
    cout << prev[x] << "\n";
    return 0;
}