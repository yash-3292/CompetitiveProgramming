#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        vector<int> arr(3);
        for(int i=0; i<3; i++){
            cin >> arr[i];
        }
        if(arr[0] > arr[1]){
            cout << "First" << endl;
        } else if(arr[0] < arr[1]){
            cout << "Second" << endl;
        } else{
            if(arr[2] % 2 != 0){
                cout << "First" << endl;
            } else{
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}