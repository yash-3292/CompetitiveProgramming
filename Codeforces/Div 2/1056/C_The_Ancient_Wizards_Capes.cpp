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
        for(int i=0; i<n; i++) cin >> arr[i];
        int allEqual = 1;
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]){
                allEqual = 0;
                break;
            }
        }
        if(allEqual){
            if(n&1){
                if((n+1)/2 == arr[0]) cout << 2 << endl;
                else cout << 0 << endl;
            } else{
                if(n/2 == arr[0] || n/2+1 == arr[0]) cout << 1 << endl;
                else cout << 0 << endl;
            }
            continue;
        }
        string s(n, '?');
        int flag = 1;
        for(int i=0; i<n-1; i++){
            if(abs(arr[i+1]-arr[i]) > 1){
                flag = 0;
                break;
            }
            if(arr[i+1]-arr[i] == 1){
                if(s[i] == '?') s[i] = '0';
                else if(s[i] == '1'){
                    flag = 0;
                    break;
                }
                s[i+1] = '0';
            } else if(arr[i+1]-arr[i] == -1){
                if(s[i] == '?') s[i] = '1';
                else if(s[i] == '0'){
                    flag = 0;
                    break;
                }
                s[i+1] = '1';
            }
        }
        if(!flag){
            cout << 0 << endl;
            continue;
        }
        for(int i=1; i<n; i++){
            if(s[i] == '?' && s[i-1] != '?'){
                if(s[i-1] == '0') s[i] = '1';
                else s[i] = '0';
            }
        }
        for(int i=n-2; i>=0; i--){
            if(s[i] == '?' && s[i+1] != '?'){
                if(s[i+1] == '0') s[i] = '1';
                else s[i] = '0';
            }
        }
        vector<int> preSum(n);
        vector<int> suffSum(n);
        preSum[0] = 0;
        for(int i=1; i<n; i++){
            preSum[i] = preSum[i-1];
            if(s[i-1] == '0') preSum[i]++;
        }
        suffSum[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            suffSum[i] = suffSum[i+1];
            if(s[i+1] == '1') suffSum[i]++;
        }
        for(int i=0; i<n; i++){
            if(preSum[i]+suffSum[i]+1 != arr[i]){
                flag = 0; 
                break;
            }
        }
        if(flag){
            cout << 1 << endl;
        } else{
            cout << 0 << endl;
        }
    }
    return 0;
}