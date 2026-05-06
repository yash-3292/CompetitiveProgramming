#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int ans = -1;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i != arr[i]){
                if(ans == -1) ans = i&arr[i];
                else ans &= (i&arr[i]);
            } 
        }
        cout << ans << endl;
    }
    return 0;
}