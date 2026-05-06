#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calc(int l, int r, vector<ll>& preSum, vector<int>& preXor){
    ll ans = preSum[r];
    int x = preXor[r];
    if(l != 0){
        ans -= preSum[l-1];
        x = (x^preXor[l-1]);
    }
    ans -= (ll)x;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<ll> preSum(n);
        preSum[0] = (ll)arr[0];
        for(int i=1; i<n; i++){
            preSum[i] = preSum[i-1] + (ll)arr[i];
        }
        vector<int> preXor(n);
        preXor[0] = arr[0];
        for(int i=1; i<n; i++){
            preXor[i] = (preXor[i-1] ^ arr[i]);
        }
        int l, r;
        cin >> l >> r;
        l--; r--;
        ll ans = calc(l, r, preSum, preXor);
        int lans = l;
        int rans = r;
        for(int i=l; i<=r; i++){
            int left = l;
            int right = i;
            int ri = i;
            int li = -1;
            while(left <= right){
                int mid = left + (right-left)/2;
                ll val = calc(mid, ri, preSum, preXor);
                if(val == ans){
                    li = mid;
                    left = mid+1;
                } else{
                    right = mid-1;
                }
            }
            if(li != -1){
                if(ri-li < rans-lans){
                    lans = li;
                    rans = ri;
                }
            }
        }
        lans++; rans++;
        cout << lans << " " << rans << endl;
    }
    return 0;
}