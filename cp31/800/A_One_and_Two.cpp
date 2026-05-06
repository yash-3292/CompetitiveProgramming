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
        int twoNo = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 2){
                twoNo++;
            }
        }
        if(twoNo % 2 != 0){
            cout << -1 << endl;
            continue;
        }
        int k;
        int no = 0;
        for(int i=0; i<n ; i++){
            if(arr[i] == 2){
                no++;
            }
            if(no == twoNo/2){
                k = i+1;
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}