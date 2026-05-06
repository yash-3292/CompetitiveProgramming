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
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        if(temp == arr){
            cout << -1 << endl;
            continue;
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if(arr[i] == temp[i]) continue;
            int val = max(temp[n-1]-temp[i], temp[i]-temp[0]);
            ans = min(ans, val);
        }
        cout << ans << endl;
    }
    return 0;
}