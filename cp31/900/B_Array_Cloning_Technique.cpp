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
        int maxNo = 0;
        map<int, int> freqMap;
        for(int i=0; i<n; i++){
            freqMap[arr[i]]++;
            maxNo = max(maxNo, freqMap[arr[i]]);
        }
        int cnt = 0;
        int temp = maxNo;
        while(temp < n){
            cnt++;
            temp *= 2;
        }
        cnt += n-maxNo;
        cout << cnt << endl;
    }
    return 0;
}