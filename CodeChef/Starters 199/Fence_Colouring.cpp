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
        int maxi = 0;
        int cnt = 1;
        int one = 0;
        if(arr[0] == 1) one++;
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]){
                maxi = max(maxi, cnt);
                cnt = 0;
            } 
            cnt++;
            if(arr[i] == 1) one++;
        }
        maxi = max(maxi, cnt);
        int ans = min(n-one, n-maxi+1);
        cout << ans << endl;
    }
    return 0;
}