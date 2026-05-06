#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPow(int num){
    return !(num&(num-1));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> sum(n);
        for(int i=0; i<n; i++){
            int cnt = 31 - __builtin_clz(arr[i]);
            sum[i] = cnt;
        }
        vector<int> preSum(n);
        preSum[0] = sum[0];
        for(int i=1; i<n; i++) preSum[i] = preSum[i-1] + sum[i];
        vector<int> B(n,0);
        vector<int> C(n,0);
        for(int i=0; i<n; i++){
            if(i == 0){
                B[i] = 0;
                C[i] = 0;
            } 
            else{
                B[i] = B[i-1];
                C[i] = C[i-1];
            }
            if(isPow(arr[i])){
            }
            else{
                if(isPow(arr[i]-1)) B[i]++;
                else C[i]++;
            }
        }
        for(int i=0; i<q; i++){
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ans = preSum[r];
            if(l > 0) ans -= preSum[l-1];
            int bcnt = B[r];
            if(l > 0) bcnt -= B[l-1];
            int ccnt = C[r];
            if(l > 0) ccnt -= C[l-1];
            ans += bcnt/2 + ccnt;
            cout << ans << endl;
        }
    }
    return 0;
}