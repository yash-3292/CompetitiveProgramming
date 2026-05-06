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
        int mini = INT_MAX;
        for(int i=0; i<n-1; i++){
            if(arr[i] <= arr[i+1]){
                int temp = (arr[i+1]-arr[i]+1) / 2;
                if((arr[i+1]-arr[i]+1) % 2 != 0){
                    temp += 1;
                }
                mini = min(mini, temp);
            } else{
                mini = 0;
                break;
            }
        }
        cout << mini << endl;
    }
    return 0;
}