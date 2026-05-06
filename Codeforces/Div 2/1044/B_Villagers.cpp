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
        int i = n-1;
        ll ans = 0;
        while(i >= 0){
            ans += arr[i];
            i -= 2;
        }
        cout << ans << endl;
    }
    return 0;
}