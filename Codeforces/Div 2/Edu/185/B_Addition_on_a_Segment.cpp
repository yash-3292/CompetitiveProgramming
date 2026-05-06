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
        sort(arr.begin(), arr.end());
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(arr[i]) ans++;
        }
        ll sum = 0;
        for(int i=0; i<n; i++) sum += arr[i];
        ans = min(ans, sum-(n-1));
        cout << ans << endl;
    }
    return 0;
}