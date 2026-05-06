#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mapPush(int x, int y, map<int,pair<int,int>>& mpp){
    if(mpp.find(x) == mpp.end()) mpp[x] = {y, y};
    else{
        mpp[x].first = min(mpp[x].first, y);
        mpp[x].second = max(mpp[x].second, y);
    }
}

ll f(int i, int c, vector<vector<int>>& arr, vector<vector<ll>>& dp){
    if(i >= arr.size()) return 0;

    if(dp[i][c] != -1) return dp[i][c];

    ll ans = (ll)(arr[i][0] - arr[i-1][0]) + (ll)(arr[i][2]-arr[i][1]);
    ll pos = (c == 1) ? arr[i-1][2] : arr[i-1][1]; 
    ll zero = (ll)abs(arr[i][2]-pos) + f(i+1, 0, arr, dp);
    ll one = (ll)abs(arr[i][1]-pos) + f(i+1, 1, arr, dp);
    ans += min(zero, one);

    return dp[i][c] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ax, ay, bx, by;
        cin >> n >> ax >> ay >> bx >> by;
        map<int, pair<int,int>> mpp;
        vector<int> x(n), y(n);
        for(int i=0; i<n; i++) cin >> x[i];
        for(int i=0; i<n; i++) cin >> y[i];
        mapPush(ax, ay, mpp);
        mapPush(bx, by, mpp);
        for(int i=0; i<n; i++){
            mapPush(x[i], y[i], mpp);
        }
        vector<vector<int>> arr;
        for(auto it : mpp){
            arr.push_back({it.first, it.second.first, it.second.second});
        }
        vector<vector<ll>> dp(arr.size(), vector<ll>(2,-1));
        ll ans = f(1, 0, arr, dp);
        cout << ans << endl;
    }
    return 0;
}