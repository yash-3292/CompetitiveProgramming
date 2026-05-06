#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int ans = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                cnt++;
            } else{
                if(cnt >= k){
                    int val = (cnt-k)/(k+1) + 1;
                    ans += val;
                }
                cnt = 0;
            }
        }
        if(cnt >= k){
            int val = (cnt-k)/(k+1) + 1;
            ans += val;
        }
        cout << ans << endl;
    }
    return 0;
}