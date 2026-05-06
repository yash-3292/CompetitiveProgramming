#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(),arr.end());
        if(arr[0] != 1){
            cout << "NO" << endl;
            continue;
        }
        ll maxi = 1;
        int flag = 1;
        for(int i=1; i<n; i++){
            if(arr[i] <= maxi) maxi += arr[i];
            else{
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}