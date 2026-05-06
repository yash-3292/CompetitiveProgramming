#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(int h, int w, vector<int>& arr){
    priority_queue<int> pq;
    for(int i=0; i<h; i++){
        pq.push(w);
    }
    for(auto it : arr){
        if(pq.empty()) return false;
        int val = pq.top();
        pq.pop();
        if(it > val) return false;
        val -= it;
        if(val){
            pq.push(val);
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, w;
        cin >> n >> w;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        int l = 1;
        int r = n+10;
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(mid, w, arr)){
                ans = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        cout << ans << endl;
    } 
    return 0;
}