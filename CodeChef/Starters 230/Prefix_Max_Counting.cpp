#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;

ll f(int i, int preMax, vector<int>& arr, vector<int>& left, vector<int>& avail, vector<vector<ll>>& dp){
    if(i == arr.size()) return 1;

    if(dp[i][preMax] != -1) return dp[i][preMax];

    if(arr[i] != -1){
        return dp[i][preMax] = f(i+1, max(arr[i], preMax), arr, left, avail, dp);
    } else{
        auto it = upper_bound(avail.begin(), avail.end(), preMax);
        if(it == avail.end()) return dp[i][preMax] = 1;
        int avoid = 1;
        int val = (avail.end()-it);
        if(left[i] == val) avoid = 0;
        ll ans = 0;
        if(avoid){
            ans = (ans + f(i+1, preMax, arr, left, avail, dp)) % mod;
        }
        ans = (ans + f(i, max(*it, preMax), arr, left, avail, dp)) % mod;
        return dp[i][preMax] =  ans;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        map<int,int> mpp;
        for(int i=1; i<=n; i++) mpp[i] = 1;
        for(int i=0; i<n; i++){
            if(arr[i] != -1){
                mpp.erase(arr[i]);
            }
        } 
        vector<int> avail;
        for(auto it : mpp) avail.push_back(it.first);
        vector<int> left(n, 0);
        for(int i=n-1; i>=0; i--){
            if(i != n-1) left[i] = left[i+1];
            if(arr[i] == -1) left[i]++;
        }
        vector<vector<ll>> dp(n, vector<ll>(n+1, -1));
        ll ans = f(0, 0, arr, left, avail, dp);
        cout << ans << endl;
    }
    return 0;
}