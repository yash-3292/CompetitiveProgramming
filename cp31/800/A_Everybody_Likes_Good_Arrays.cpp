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
        int sum = 0;
        for(int i=0; i<n-1; i++){
            if(arr[i] % 2 == arr[i+1] % 2){
                sum ++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}