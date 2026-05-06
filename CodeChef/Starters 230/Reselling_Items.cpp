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
        sort(arr.begin(), arr.end(), greater<int>());
        int ans = 0;
        for(int i=0; i<n; i++){
            if(k){
                if(arr[i] > 5){
                    ans += arr[i]-5;
                    k--;
                }
            } else{
                if(arr[i] > 10){
                    ans += arr[i]-10;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}