#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,vector<int>> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]].push_back(i);
    }
    vector<int> next(n, -1);
    for(auto it : mpp){
        int sz = it.second.size();
        for(int i=0; i<sz; i++){
            if(i+it.first-1 >= sz){
                break;
            }
            next[it.second[i]] = it.second[i+it.first-1];
        }
    }
    vector<int> dp(n+1, 0);
    for(int i=n-1; i>=0; i--){
        int notTake = dp[i+1];
        int take = 0;
        if(next[i] != -1){
            take = arr[i] + dp[next[i]+1];
        }
        dp[i] = max(take, notTake);
    }
    cout << dp[0] << endl;
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