#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int k, vector<pair<int,int>>& arr){
    int n = arr.size();
    int i = 0;
    if(i == k) return true;
    for(auto it : arr){
        if(it.second >= i && it.first >= k-i-1) i++;
        if(i == k) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        int lo = 1;
        int hi = n;
        int ans = 1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, arr)){
                ans = mid;
                lo = mid+1;
            } else{
                hi = mid-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}