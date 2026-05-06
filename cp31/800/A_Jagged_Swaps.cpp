#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n ;i++){
            cin >> arr[i];
        }
        if(arr[0] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}