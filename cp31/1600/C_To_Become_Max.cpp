#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int val, int k_ori, vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        int k = k_ori;
        int possible = 1;
        int j;
        for(j=i; j<n; j++){
            int temp = val+i-j;
            if(arr[j] >= temp) break;
            else{
                if(k >= temp-arr[j]){
                    k -= temp-arr[j];
                } else{
                    possible = 0;
                    break;
                }
            }
        }
        if(possible && j != n) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int lo = 1;
        int hi = 1e9;
        int ans;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid, k, arr)){
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