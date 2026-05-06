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
        for(int i=0; i<n; i++){
            cin >> arr[i];
            arr[i] = min(arr[i], 7-arr[i]);
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]) continue;
            if(i == n-1) ans++;
            else{
                ans++;
                for(int j=1; j<=3; j++){
                    if(arr[i-1] != j && arr[i+1] != j){
                        arr[i] = j;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}