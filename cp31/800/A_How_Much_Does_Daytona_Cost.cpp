#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int appear = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == k){
                cout << "YES" << endl;
                appear = 1;
                break;
            }
        }
        if(appear == 0){
            cout << "NO" << endl;
        }
    }
    return 0;
}