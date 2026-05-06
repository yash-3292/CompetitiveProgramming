#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int direct = 0;
    int myor = arr[0];
    for(int i=1; i<n; i++){
        if(myor | arr[i] == myor){
            direct = 1;
            break;
        }
    }
    int ans = 0;
    if(direct == 0){
        for(int i=1; i<n; i++){
            ans = ans | arr[i];
        }
        cout << ans << endl;
    } else {
        for(int i=0; i<n; i++){
            ans = ans | arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}