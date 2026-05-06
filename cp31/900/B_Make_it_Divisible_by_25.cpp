#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<int> arr;
        ll temp = n;
        while(temp != 0){
            arr.push_back(temp%10);
            temp /= 10;
        }
        map<int, int> freqMap;
        int ans;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == 5 && freqMap.find(0) != freqMap.end()){
                ans = i-1;
                break;
            } else if(arr[i] == 7 && freqMap.find(5) != freqMap.end()){
                ans = i-1;
                break;
            } else if(arr[i] == 2 && freqMap.find(5) != freqMap.end()){
                ans = i-1;
                break;
            } else if(arr[i] == 0 && freqMap.find(0) != freqMap.end()){
                ans = i-1;
                break;
            }
            freqMap[arr[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}