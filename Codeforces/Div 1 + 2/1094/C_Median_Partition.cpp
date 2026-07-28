#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    int median = temp[n/2];
    vector<int> garr(n+1, 0);
    vector<int> larr(n+1, 0);
    for(int i=1; i<=n; i++){
        if(arr[i-1] > median) garr[i] = 1;
        else if(arr[i-1] < median) larr[i] = 1;
    }
    for(int i=1; i<=n; i++) garr[i] += garr[i-1];
    for(int i=1; i<=n; i++) larr[i] += larr[i-1];
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            int len = i-j;
            int g = garr[i] - garr[j];
            int l = larr[i] - larr[j];
            if((len%2 == 1) && g <= len/2 && l <= len/2){
                if(dp[j] == -1) continue;
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    cout << dp[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}