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
        int ans = -1;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]){
                ans = i;
                break;
            } 
        }
        if(ans == -1) cout << -1 << endl;
        else cout << ans << " " << ans+1 << endl;
    }
    return 0;
}