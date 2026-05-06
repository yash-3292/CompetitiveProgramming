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
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        if(n == 1){
            cout << 0 << endl;
            continue;
        } 
        if(n == 2){
            cout << abs(arr[0] - arr[1]) << endl;
            continue;
        }
        int temp = 0;
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                temp = max(temp, arr[i]-arr[i+1]);
            }
        }
        temp = max(temp, maxi-arr[0]);
        temp = max(temp,  arr[n-1]-mini);
        cout << temp << endl;
    }
    return 0;
}
