#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int ans = 0;
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i-1] < 2*arr[i]){
                cnt++;
            } else{
                if(cnt > k){
                    ans += cnt - k;
                }
                cnt = 1;
            }
        }
        if(cnt > k){
            ans += cnt - k;
        }
        cout << ans << endl;
    }
    return 0;
}