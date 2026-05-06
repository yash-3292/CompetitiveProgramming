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
        vector<int> c(n);
        for(int i=0; i<n; i++) cin >> c[i];
        int mini = c[0];
        int ans = 0;
        for(int i=0; i<n; i++){
            mini = min(mini, c[i]);
            ans += arr[i]*mini;
        }
        cout << ans << endl;
    }
    return 0;
}