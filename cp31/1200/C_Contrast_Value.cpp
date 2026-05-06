#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        bool isAllSame = true;
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]){
                isAllSame = false;
                break;
            }
        }
        if(n == 1 || isAllSame){
            cout << 1 << endl;
            continue;
        }
        int cnt = 2;
        isAllSame = true;
        bool up = true;
        for(int i=1; i<n-1; i++){
            if(arr[i] != arr[i-1]) isAllSame = false;
            if(arr[i] > arr[i-1]) up = true;
            else if(arr[i] < arr[i-1]) up = false;
            if(arr[i-1] <= arr[i] && arr[i] > arr[i+1]){
                if(up && !isAllSame) cnt++; 
            } else if(arr[i-1] >= arr[i] && arr[i] < arr[i+1]){
                if(!up && !isAllSame) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}