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
        int oddSum = 0;
        int evenSum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(i&1) oddSum += arr[i];
            else evenSum += arr[i];
        }
        int maxSum = max(oddSum, evenSum);
        cout << maxSum << endl;
    }
    return 0;
}