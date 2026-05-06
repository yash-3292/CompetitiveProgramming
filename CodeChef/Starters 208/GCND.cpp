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
        for(int i=0; i<n; i++){
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        int maxicnt = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == maxi) maxicnt++;
            else if(arr[i] < maxi-1) cnt++;
        }
        int ans;
        if(cnt > 0 || maxicnt > 1){
            ans = maxi-1;
        } else{
            ans = maxi-2;
        }
        cout << ans << endl;
    }
    return 0;
}