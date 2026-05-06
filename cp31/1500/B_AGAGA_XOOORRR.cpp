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
        int xorr = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            xorr ^= arr[i];
        }
        int flag = 1;
        if(xorr != 0){
            int i;
            int temp = 0;
            for(i=0; i<n; i++){
                temp ^= arr[i];
                if(temp == xorr) break;
            }
            if(i == n-1){
                flag = 0;
            } else{
                i++;
                int exist = 0;
                for(;i<n; i++){
                    temp ^= arr[i];
                    if(temp == 0){
                        exist = 1;
                        break;
                    } 
                }
                if(!exist) flag = 0;
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