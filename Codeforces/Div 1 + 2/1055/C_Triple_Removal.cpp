#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> preSum(n,0);
        preSum[0] = arr[0];
        for(int i=1; i<n; i++) preSum[i] = preSum[i-1] + arr[i];
        vector<int> same(n);
        same[0] = 0;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                same[i] = same[i-1] + 1;
            } else{
                same[i] = same[i-1];
            }
        }
        for(int i=0; i<q; i++){
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int size = r-l+1;
            if((size%3) != 0){
                cout << -1 << endl;
                continue;
            }
            int one = preSum[r];
            if(l > 0) one -= preSum[l-1];
            if(one%3 != 0){
                cout << -1 << endl;
                continue;
            }
            int ans = size/3;
            int consecutive = same[r]-same[l];
            if(consecutive == 0) ans++;
            cout << ans << endl;
        }
    }
    return 0;
}