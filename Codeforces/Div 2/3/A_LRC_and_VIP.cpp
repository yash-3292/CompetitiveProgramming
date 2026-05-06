#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int flag = 1;
        int maxi = INT_MIN;
        int maxind = -1;
        for(int i=0; i<n; i++){
            if(arr[0] != arr[i]) flag = 0;
            if(maxi < arr[i]){
                maxi = arr[i];
                maxind = i;
            }
        }
        if(flag){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        for(int i=0; i<n; i++){
            if(i == maxind){
                cout << "2 ";
                continue;
            }
            cout << "1 ";
        }
        cout << endl;
    }
    return 0;
}