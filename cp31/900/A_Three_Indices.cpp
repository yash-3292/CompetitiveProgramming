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
        for(int i=0; i<n; i++) cin >> arr[i];
        int ans = 0;
        for(int i=1; i<n-1; i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                ans = i+1;
                break;
            }
        }
        if(ans){
            cout << "YES" << endl;
            cout << ans-1 << " " << ans << " " << ans+1 << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}