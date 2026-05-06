#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<ll> mpp(31, 0);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            int val = 0;
            while(arr[i] >> val != 0){
                val++;
            }
            mpp[val]++;
        }
        ll cnt = 0;
        for(int i=0; i<31; i++){
            if(mpp[i] > 1){
                cnt += (mpp[i] * (mpp[i] - (ll)1)) / (ll)2;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}