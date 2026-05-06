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
        int maxi = 0;
        int i = 0;
        int j = n - 1;
        int sum1 = arr[0];
        int sum2 = arr[n-1];
        while(i < j){
            if(sum1 == sum2){
                maxi = i + 1 + n - j;
                i++;
                j--;
                sum1 += arr[i];
                sum2 += arr[j];
            } else if(sum1 > sum2){
                j--;
                sum2 += arr[j];
            } else{
                i++;
                sum1 += arr[i];
            }
        }
        cout << maxi << endl;
    }
    return 0;
}