#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int i=0;
    int num = 0;
    while(num <= sum/2){
        num += arr[i];
        i++;
    }
    cout << i << endl;
    return 0;
}