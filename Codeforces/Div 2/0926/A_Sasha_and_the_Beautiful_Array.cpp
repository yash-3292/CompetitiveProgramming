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
        int maxi = 0;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
        int ans = maxi - mini;
        cout << ans << endl;
    }
    return 0;
}