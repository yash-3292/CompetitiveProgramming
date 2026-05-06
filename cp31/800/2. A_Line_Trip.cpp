#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int vol = 0;
        for(int i=0; i<n; i++){
            if(i == 0){
                vol = max(vol, arr[i]);
                continue;
            }
            vol = max(vol, arr[i]-arr[i-1]);
        }
        vol = max(vol, 2*(x-arr[n-1]));
        cout << vol << endl;
    }
    return 0;
}