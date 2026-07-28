#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n; 
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> preSum(n);
    preSum[0] = arr[0];
    for(int i=1; i<n; i++) preSum[i] = preSum[i-1] + arr[i];
    for(int l=1; l<n; l++){
        for(int r=l+1; r<n; r++){
            int s1 = preSum[l-1] % 3;
            int s2 = (preSum[r-1] - preSum[l-1]) % 3;
            int s3 = (preSum[n-1] - preSum[r-1]) % 3;
            if(s1 == s2 && s2 == s3){
                cout << l << " " << r << endl;
                return;
            } 
            if(s1 != s2 && s2 != s3 && s1 != s3){
                cout << l << " " << r << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}