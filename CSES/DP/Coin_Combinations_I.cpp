#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for(int i=1; i<=x; i++){
        for(int j=0; j<n; j++){
            if(arr[j] > i) break;
            dp[i] = (dp[i]+dp[i-arr[j]])%mod;
        }
    }
    cout << dp[x] << "\n";
    return 0;
}