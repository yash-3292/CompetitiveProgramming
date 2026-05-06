#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        if(arr[0] == arr[n-1]){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << arr[n-1] << " ";
        for(int i=0; i<n-1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}