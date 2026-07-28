#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int,int> f(int l, int r, vector<int>& arr){
    if(l > r) return {0,0};
    int maxans = 0;
    int minans = 0;
    int maxcnt = 0;
    int mincnt = 0;
    for(int i=l; i<=r; i++){
        maxcnt += arr[i];
        mincnt += arr[i];
        maxans = max(maxcnt, maxans);
        minans = min(mincnt, minans);
        if(maxcnt < 0) maxcnt = 0;
        if(mincnt > 0) mincnt = 0;
    }
    return {minans, maxans};
}

pair<int,int> f1(int l, int r, vector<int>& arr){
    if(l > r) return {0,0};
    int maxans = 0;
    int minans = 0;
    int cnt = 0;
    for(int i=l; i<=r; i++){
        cnt += arr[i];
        maxans = max(cnt, maxans);
        minans = min(cnt, minans);
    }
    return {minans, maxans};
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> vis;
    int idx = -1;
    for(int i=0; i<n; i++){
        if(arr[i] != 1 && arr[i] != -1){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        auto it = f(0, n-1, arr);
        for(int i=it.first; i<=it.second; i++){
            vis[i] = 1;
        }
    } else{
        auto it1 = f(0, idx-1, arr);
        auto it2 = f(idx+1, n-1, arr);
        for(int i=it1.first; i<=it1.second; i++){
            vis[i] = 1;
        }
        for(int i=it2.first; i<=it2.second; i++){
            vis[i] = 1;
        }
        auto it3 = f1(idx+1, n-1, arr);
        if(idx-1 >= 0){
            reverse(arr.begin(), arr.begin()+idx);
            auto it4 = f1(0, idx-1, arr);
            it3.first += it4.first;
            it3.second += it4.second;
            reverse(arr.begin(), arr.begin()+idx);
        }
        for(int i=it3.first; i<=it3.second; i++){
            vis[i+arr[idx]] = 1;
        }
    }
    cout << vis.size() << endl;
    for(auto it : vis){
        cout << it.first << " ";
    }
    cout << endl;
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