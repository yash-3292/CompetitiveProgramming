#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int a = 0;
        int b = 0;
        int flag = 1;
        for(int i=0; i<n; i++) cin >> arr[i];
        for(int i=0; i<n; i++){
            if(arr[i] > 1){
                a++;
                b++;
            } else{
                if(flag){
                    a++;
                    b++;
                    flag = 0;
                    continue;
                }
                if(a > b) b++;
                else a++;
            }
        }
        int ans = min(a, b);
        cout << ans << endl;
    }
    return 0;
}