#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,pair<int,int>> mpp;
    for(int i=0; i<n; i++){
        if(mpp.find(arr[i]) != mpp.end()){
            mpp[arr[i]].first = min(mpp[arr[i]].first, i);
            mpp[arr[i]].second = max(mpp[arr[i]].second, i);
        } else{
            mpp[arr[i]] = {i,i};
        }
    }
    int ans = INT_MAX;
    for(auto it : mpp){
        int mini = it.second.first;
        int maxi = it.second.second;
        if(mini == maxi) continue;
        ans = min(ans, mini + n - maxi - 1);
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
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