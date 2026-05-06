#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    vector<vector<int>> dp;
    for(int i=0; i<=30; i++){
        vector<int> temp;
        for(int j=0; j<=i; j++){
            if(j == 0 || j == i) temp.push_back(1);
            else temp.push_back(dp.back()[j-1] + dp.back()[j]);
        }
        dp.push_back(temp);
    }
    for(int i=0; i<=30; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] += dp[i][j-1];
        }
    }
    while(t--){
        int n, k;
        cin >> n >> k;
        int d = 0;
        int temp = n;
        while(temp){
            temp /= 2;
            d++;
        }
        d--;
        ll ans =  0;
        for(int i=0; i<d; i++){
            int j = k-i-1;
            if(j < 0) continue;
            j = min(j, i);
            ans += (ll)dp[i][j];
        }
        if(d+1 <= k) ans++;
        ans = (ll)n - ans;
        cout << ans << endl;
    }
    return 0;
}