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
        ll total = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= q){
                cnt++;
                continue;
            }
            if(arr[i] > q && cnt != 0){
                ll temp = (ll)cnt - (ll)k + 1;
                if(temp > 0){
                    total += temp*(temp+1)/2;
                }
                cnt = 0;
            }
        }
        if(cnt != 0){
            ll temp = (ll)cnt - (ll)k + 1;
            if(temp > 0){
                total += temp*(temp+1)/2;
            }
            cnt = 0;
        }

        cout << total << endl;
    }
    return 0;
}
