#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int n, vector<int>& arr, vector<int>& next, vector<int>& dp){
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int notTake = f(i+1, n, arr, next, dp);
    int take = arr[i] + f(next[i], n, arr, next, dp);

    return dp[i] = max(take, notTake);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> entry(n), exit(n);
        vector<pair<int,int>> cat(m);
        for(int i=0; i<m; i++){
            cin >> cat[i].first >> cat[i].second;
            cat[i].first--; cat[i].second--;
            entry[cat[i].first].push_back(i);
            exit[cat[i].second].push_back(i);
        }
        map<int,int> mpp;
        vector<int> arr(n, 0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += entry[i].size();
            arr[i] = cnt;
            cnt -= exit[i].size();
        }
        vector<int> next(n);
        for(int i=n-1; i>=0; i--){
            for(auto ind : exit[i]){
                mpp[cat[ind].second]++;
            }
            if(mpp.empty()) next[i] = i+1;
            else next[i] = mpp.rbegin()->first+1;
            for(auto ind : entry[i]){
                mpp[cat[ind].second]--;
                if(mpp[cat[ind].second] == 0){
                    mpp.erase(cat[ind].second);
                }
            }
        }
        vector<int> dp(n, -1);
        int ans = f(0, n, arr, next, dp);
        cout << ans << endl;
    }
    return 0;
}