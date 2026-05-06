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
        int flag = 1;
        for(int i=0; i<n; i++){
            if(arr[i] != 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            if(n&1) cout << 998244353 << endl;
            else cout << 0 << endl;
        } else{
            cout << 499122177 << endl;
        }
    }
    return 0;
}