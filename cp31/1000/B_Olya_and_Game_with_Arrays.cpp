#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mini = INT_MAX;
        int secondmini = INT_MAX;
        int cnt = 0;
        ll sum = 0;
        while(n--){
            int m;
            cin >> m;
            vector<int> arr(m);
            for(int i=0; i<m; i++) cin >> arr[i];
            sort(arr.begin(), arr.end());
            sum += (ll)arr[1];
            secondmini = min(secondmini, arr[1]);
            mini = min(mini, arr[0]);
        }
        ll ans = sum - (ll)secondmini + (ll)mini;
        cout << ans << endl;
    }
    return 0;
}
