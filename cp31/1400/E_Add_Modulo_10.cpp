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
        int flag1 = 0;
        int flag2 = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=0; i<n; i++){
            if(arr[i]%10 == 5){
                flag1 = 1;
                for(int j=0; j<n; j++){
                    if(arr[j] != arr[i] && arr[j] != arr[i]+5){
                        flag2 = 1;
                        break;
                    }
                }
                break;
            }
            if(arr[i]%10 == 0){
                flag1 = 1;
                for(int j=0; j<n; j++){
                    if(arr[j] != arr[i] && arr[j] != arr[i]-5){
                        flag2 = 1;
                        break;
                    }
                }
                break;
            }
        } 
        if(flag1){
            if(flag2) cout << "No" << endl;
            else cout << "Yes" << endl;
            continue;
        }
        for(int i=0; i<n; i++){
            while(arr[i]%10 != 2){
                arr[i] = arr[i] + arr[i]%10;
            }
        }
        int flag = 1;
        for(int i=1; i<n; i++){
            if((arr[i] - arr[0])%20 != 0){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}