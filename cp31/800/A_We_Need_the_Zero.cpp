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
        int xsor = 0;
        for(int i=0; i<n; i++){
            xsor ^= arr[i];
        }
        if(n % 2 != 0){
            cout << xsor << endl;
        } else{
            if(xsor == 0){
                cout << 10 << endl;
            } else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}