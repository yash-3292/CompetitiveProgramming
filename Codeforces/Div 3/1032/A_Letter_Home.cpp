#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n==1){
            int ans = abs(s-arr[0]);
            cout << ans << endl;
            continue;
        }
        if(s >= arr[n-1]){
            int ans = s - arr[0];
            cout << ans << endl;
        } else if(s <= arr[0]){
            int ans = arr[n-1] - s;
            cout << ans << endl;
        } else{
            int val1 = arr[n-1] - s;
            int val2 = s - arr[0];
            int ans = min(2*val1 + val2, 2*val2 + val1);
            cout << ans << endl;
        }
    }
    return 0;
}