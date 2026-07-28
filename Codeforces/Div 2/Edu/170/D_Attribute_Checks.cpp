#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int intell, vector<vector<int>>& strength, vector<vector<int>>& intelligence, vector<vector<int>>& dp){
    if(i == strength.size()) return 0;

    if(dp[i][intell] != -1) return dp[i][intell];

    int stren = i-intell;
    int take1 = 0;
    if(intell+1 < strength[0].size()) take1 = intelligence[i][intell+1] + f(i+1, intell+1, strength, intelligence, dp);
    int take2 = 0;
    if(stren+1 < strength[0].size()) take2 = strength[i][stren+1] + f(i+1, intell, strength, intelligence, dp);

    int ans = max(take1, take2);

    return dp[i][intell] = ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i].first;
    int idx = 0;
    int ans = 0;
    int end = n-1;
    for(int i=0; i<n; i++){
        if(arr[i].first == 0){
            if(idx <= 2*m-1){
                arr[i].second = idx;
                idx++;
                if(idx == 2*m){
                    end = i;
                }
            } else{
                arr[i].second = -1;
            }
        } else{
            if(idx == 2*m){
                ans++;
            }
            arr[i].second = -1;
        }
    }
    vector<vector<int>> strength(idx), intelligence(idx);
    vector<int> curstrength(m+1, 0), curintelligence(m+1, 0);
    for(int i=end; i>=0; i--){
        if(arr[i].first == 0){
            strength[arr[i].second] = curstrength;
            intelligence[arr[i].second] = curintelligence;
        } else{
            if(arr[i].first > 0){
                curintelligence[arr[i].first]++;
            } else{
                curstrength[abs(arr[i].first)]++;
            }
        }
    }
    if(strength.size() == 0){
        cout << ans << endl;
        return;
    }
    vector<vector<int>> dp(idx+1, vector<int>(idx+1, -1));
    ans += f(0, 0, strength, intelligence, dp);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}