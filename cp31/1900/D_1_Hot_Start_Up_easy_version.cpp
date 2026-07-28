#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) arr[i]--;
    vector<int> cold(k), hot(k);
    for(int i=0; i<k; i++) cin >> cold[i];
    for(int i=0; i<k; i++) cin >> hot[i];
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(k+1, 0)));
    for(int i=n-1; i>=0; i--){
        for(int turn=0; turn<2; turn++){
            for(int prog=0; prog<k+1; prog++){
                ll take0 = 0;
                ll take1 = 0;
                ll prog0 = k;
                ll prog1 = k;
                if(turn == 0){
                    prog0 = prog;
                    if(i != 0) prog1 = arr[i-1];
                } else{
                    prog1 = prog;
                    if(i != 0) prog0 = arr[i-1];
                }
                take0 += (prog0 == arr[i]) ? hot[arr[i]] : cold[arr[i]];
                take1 += (prog1 == arr[i]) ? hot[arr[i]] : cold[arr[i]];
                take0 += dp[i+1][1][prog1];
                take1 += dp[i+1][0][prog0];

                ll ans = min(take0, take1);
                dp[i][turn][prog] = ans;
            }
        }
    }
    ll ans = dp[0][0][k];
    cout << ans << endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}