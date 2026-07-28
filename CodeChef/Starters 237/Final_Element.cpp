#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> temp;
    int i = 0;
    int j = 0;
    int xorr = 0;
    while(j < n){
        xorr = (xorr ^ arr[j]);
        if(j-i+1 > k){
            xorr = (xorr ^ arr[i]);
            i++;
        }
        if(j-i+1 == k) temp.push_back(xorr);
        j++;
    }
    arr = temp;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int k = (1<<30);
        int cnt = 5;
        while(arr.size() != 1){
            cnt--;
            if(!cnt) break;
            while(k > arr.size()) k >>= 1;
            f(arr, k);
        }
        cout << arr[0] << endl;
    }
    return 0;
}