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
        vector<int> longSub(n+1, 0);
        for(int i=0; i<n; i++) cin >> arr[i];
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]) cnt++;
            else{
                int val = arr[i-1];
                longSub[val] = max(longSub[val], cnt);
                cnt = 1;
            }
        }
        int val = arr[n-1];
        longSub[val] = max(longSub[val], cnt);
        ll mini = 1e18;
        for(int i=1; i<=n; i++){
            if(longSub[i] == 0) continue;
            ll num = ((ll)n - (ll)longSub[i]) * (ll)i;
            mini = min(mini, num);
        }
        cout << mini << endl;
    }
    return 0;
}