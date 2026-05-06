#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, int n, vector<pair<int,int>>& seg, vector<int>& queries){
    vector<int> arr(n+1,0);
    for(int i=0; i<=mid; i++){
        arr[queries[i]]++;
    }
    for(int i=1; i<n+1; i++) arr[i] = arr[i] + arr[i-1];
    for(auto it : seg){
        int l = it.first;
        int r = it.second;
        int one = arr[r];
        if(l > 0) one -= arr[l-1];
        int zero = r-l+1-one;
        if(one > zero) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> seg(m);
        for(int i=0; i<m; i++) cin >> seg[i].first >> seg[i].second;
        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i=0; i<q; i++) cin >> queries[i];
        int lo = 0;
        int hi = q-1;
        int ans = -2;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, n, seg, queries)){
                ans = mid;
                hi = mid-1;
            } else{
                lo = mid+1;
            }
        }
        ans++;
        cout << ans << endl;
    }
    return 0;
}