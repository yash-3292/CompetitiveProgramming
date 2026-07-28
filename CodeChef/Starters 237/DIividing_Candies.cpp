#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i]%x == 0){
                ans = max(ans, arr[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}