#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++) arr[i] -= i;
        int l = 0;
        int r = 0;
        map<int,int> freq;
        map<int,int> mpp;
        vector<int> ans(n);
        while(r < n){
            freq[arr[r]]++;
            mpp[freq[arr[r]]]++;
            if(freq[arr[r]]-1 > 0) mpp[freq[arr[r]]-1]--;
            if(mpp[freq[arr[r]]-1] == 0){
                mpp.erase(freq[arr[r]]-1);
            }
            if(r-l+1 > k){
                mpp[freq[arr[l]]]--;
                if(mpp[freq[arr[l]]] == 0){
                    mpp.erase(freq[arr[l]]);
                }
                freq[arr[l]]--;
                if(freq[arr[l]] > 0) mpp[freq[arr[l]]]++;
                l++;
            }
            if(r-l+1 == k){
                ans[r] = mpp.rbegin()->first;
            }
            r++;
        }
        while(q--){
            cin >> l >> r;
            l--; r--;
            int val = k - ans[r];
            cout << val << endl;
        }
    }
    return 0;
}