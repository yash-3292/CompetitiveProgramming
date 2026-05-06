#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++) cin >> arr[i];
        int l = 1;
        ll ans = 0;
        for(int i=1; i<=n; i++){
            int val = arr[i] - i;
            if(val < 0){
                int j = -val;
                l = max(l, j+1);
            }
            ans += (ll)(i-l+1);
        }
        cout << ans << "\n";
    }
    return 0;
}