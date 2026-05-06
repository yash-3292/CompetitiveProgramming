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
        if(k >= 2){
            cout << "YES" << endl;
            continue;
        }
        int sorted = 1;
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                sorted = 0;
            }
        }
        if(sorted){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}