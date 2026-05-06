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
        int maxi = 0;
        int ans = 0;
        for(int i=0; i<n; i++) maxi = max(maxi, arr[i]);
        for(int i=0; i<n; i++) if(arr[i] == maxi) ans++;
        cout << ans << endl;
    }
    return 0;
}