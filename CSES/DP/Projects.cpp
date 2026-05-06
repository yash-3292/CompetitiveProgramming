#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, int n, vector<vector<int>>& arr, map<int,int>& mpp, vector<ll>& dp){
    if(i >= n) return 0;

    if(dp[i] != -1) return dp[i];

    ll notTake = f(i+1, n, arr, mpp, dp);
    auto it = mpp.upper_bound(arr[i][1]);

    int ind = (it==mpp.end()) ? n : it->second;
    ll take = f(ind, n, arr, mpp, dp) + (ll)arr[i][2];

    return dp[i] = max(take, notTake);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for(int i=0; i<n; i++){
        int a, b, p;
        cin >> a >> b >> p;
        arr.push_back({a, b, p});
    }
    sort(arr.begin(), arr.end());
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        if(mpp.find(arr[i][0]) == mpp.end()) mpp[arr[i][0]] = i;
    }
    vector<ll> dp(n, -1);
    ll ans = f(0, n, arr, mpp, dp);
    cout << ans << endl;
    return 0;
}