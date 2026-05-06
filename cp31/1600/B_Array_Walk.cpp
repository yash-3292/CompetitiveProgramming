#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int ki, int zi, int opt, int k, int z, vector<int>& arr, vector<vector<vector<int>>>& dp){
    if(ki == 0) return 0;

    if(dp[ki][zi][opt] != -1) return dp[ki][zi][opt];

    int i = k - ki - 2*(z-zi);
    int ans = 0;
    if(zi > 0 && ki > 0 && opt){
        int val = arr[i-1] + f(ki-1, zi-1, 0, k, z, arr, dp);
        ans = max(ans, val);
    }
    int val = arr[i+1] + f(ki-1, zi, 1, k, z, arr, dp);
    ans = max(ans, val);

    return dp[ki][zi][opt] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(z+1, vector<int>(2,-1)));
        int ans = arr[0] + f(k, z, 0, k, z, arr, dp);
        cout << ans << endl;
    }
    return 0;
}