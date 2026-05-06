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
        int flag = true;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] == 0) flag = false;
        } 
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        int val = -1;
        for(int i=0; i<n; i++){
            if(arr[i] != -1){
                if(val == -1){
                    val = arr[i];
                } else{
                    if(val != arr[i]){
                        flag = false;
                        break;
                    }
                }
            }
        }  
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;     
    }
    return 0;
}