#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> vis(n+1, 0);
    vector<pair<int,int>> mapx(n+1,{-1,-1});
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        vis[y] = 1;
        if(mapx[x].first != -1 || mapx[x].second != -1){
            mapx[x].first = min(mapx[x].first, y);
            mapx[x].second = max(mapx[x].second, y);
        } else{
            mapx[x] = {y, y};
        }
    }
    vector<pair<int,int>> arr;
    for(int i=1; i<=n; i++){
        if(mapx[i].first != -1 || mapx[i].second != -1) arr.push_back(mapx[i]);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        vis[i] += vis[i-1];
    }
    int m = arr.size();
    vector<int> preMin(m), preMax(m), sufMin(m), sufMax(m);
    preMin[0] = arr[0].first;
    for(int i=1; i<m; i++) preMin[i] = min(preMin[i-1], arr[i].first);
    preMax[0] = arr[0].second;
    for(int i=1; i<m; i++) preMax[i] = max(preMax[i-1], arr[i].second);
    sufMin[m-1] = arr[m-1].first;
    for(int i=m-2; i>=0; i--) sufMin[i] = min(sufMin[i+1], arr[i].first);
    sufMax[m-1] = arr[m-1].second;
    for(int i=m-2; i>=0; i--) sufMax[i] = max(sufMax[i+1], arr[i].second);
    ll ans = 0;
    for(int i=1; i<m; i++){
        int mini = max(preMin[i-1], sufMin[i]);
        int maxi = min(preMax[i-1], sufMax[i]);
        if(mini >= maxi) continue;
        ans += (ll)vis[maxi] - (ll)vis[mini];
    }
    cout << ans << endl;
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