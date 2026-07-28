#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(int i, int cnt, int n, vector<int>& nge, vector<pair<int,int>>& ans, vector<vector<int>>& dp){
    if(cnt > n) return false;
    if(i == 2*n) return cnt == n;

    if(dp[i][cnt] != -1) return dp[i][cnt];

    if(f(nge[i], cnt, n, nge, ans, dp)) return true;
    ans.push_back({i, nge[i]-1});
    if(f(nge[i], cnt+nge[i]-i, n, nge,ans, dp)) return true;
    ans.pop_back();

    return dp[i][cnt] = false;
} 

void solve(){
    int n;
    cin >> n;
    vector<int> arr(2*n);
    for(int i=0; i<2*n; i++) cin >> arr[i];
    vector<int> nge(2*n);
    stack<int> st;
    for(int i=2*n-1; i>=0; i--){
        while(!st.empty() && arr[i] >= arr[st.top()]) st.pop();
        nge[i] = (st.empty()) ? 2*n : st.top();
        st.push(i);
    }
    vector<pair<int,int>> ans;
    vector<vector<int>> dp(2*n, vector<int>(n, -1)); 
    bool flag = f(0, 0, n, nge, ans, dp);
    if(!flag){
        cout << -1 << endl;
        return;
    }
    vector<int> mpp(2*n, 0);
    for(auto it : ans){
        for(int i=it.first; i<=it.second; i++) mpp[i]++;
    }
    for(int i=0; i<2*n; i++) if(mpp[i]) cout << arr[i] << " ";
    cout << endl;
    for(int i=0; i<2*n; i++) if(!mpp[i]) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    solve();
    return 0;
}