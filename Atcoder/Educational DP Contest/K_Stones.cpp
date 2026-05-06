#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> dp(k+1);
    for(int i=0; i<=k; i++){
        if(i < arr[0]){
            dp[i] = 0;
            continue;
        }
        int ans = 0;
        for(auto it : arr){
            if(i >= it){
                if(dp[i-it] == 0){
                    ans = 1;
                    break;
                } 
            }
        }
        dp[i] = ans;
    }
    int ans = dp[k];
    if(ans){
        cout << "First" << endl;
    } else{
        cout << "Second" << endl;
    }
    return 0;
}