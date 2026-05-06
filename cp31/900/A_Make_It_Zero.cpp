#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        bool allZero = true;
        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                allZero = false;
                break;
            }
        }
        if(allZero){
            cout << 0 << endl;
            continue;
        }
        if(n & 1){
            cout << 4 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << " " << 2 << endl;
            cout << 2 << " " << n << endl;
            cout << 2 << " " << n << endl;
        } else{
            cout << 2 << endl;
            cout << 1 << " " << n << endl;
            cout << 1 << " " << n << endl;
        }
    }
    return 0;
}