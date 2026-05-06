#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int allOne = 1;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] == 0) allOne = 0;
        } 
        if(allOne){
            cout << "YES" << endl;
            continue;
        }
        if(arr[0] == 0 && arr[1] == 0){
            cout << "YES" << endl;
            continue;
        } else if(arr[n-1] == 0 && arr[n-2] == 0){
            cout << "YES" << endl;
            continue;
        }
        int flag = 0;
        for(int i=1; i<n-2; i++){
            if(arr[i] == 0){
                if(arr[i-1] != 1 || arr[i+1] != 1){
                    flag = 1;
                    break;
                }
            } 
        }
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }

    }
    return 0;
}