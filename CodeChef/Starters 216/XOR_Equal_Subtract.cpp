#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        vector<int> dp(n, 1);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if((arr[i]&arr[j]) == arr[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}