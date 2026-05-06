#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int opt, int n, vector<int>& arr, vector<vector<int>>& pos, vector<vector<int>>& dp){
    if(i == n) return 0;

    if(dp[i][opt] != -1) return dp[i][opt];

    int ans = f(i+1, 0, n, arr, pos, dp);
    int val = arr[i];
    if(pos[val].size() != 0){
        auto it = upper_bound(pos[val].begin(), pos[val].end(), i);
        if(it != pos[val].end()){
            int take;
            if(opt) take = *it - i + f(*it, 1, n, arr, pos, dp);
            else take = *it - i + 1 + f(*it, 1, n, arr, pos, dp);
            ans = max(ans, take);
        }
    }

    return dp[i][opt] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            x--;
            arr[i] = x;
        } 
        vector<vector<int>> pos(n);
        for(int i=0; i<n; i++){
            pos[arr[i]].push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans = f(0, 0, n, arr, pos, dp);
        cout << ans << endl;
    }
    return 0;
}