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
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        int flag = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > sum-arr[i]) flag = 1; 
        }
        if(flag){
            cout << "T" << endl;
        } else if(sum&1){
            cout << "T" << endl;
        } else{
            cout << "HL" << endl;
        }
    }
    return 0;
}