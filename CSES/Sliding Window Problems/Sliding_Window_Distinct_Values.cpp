#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> mpp;
    int i = 0;
    int j = 0;
    while(j < n){
        mpp[arr[j]]++;
        if(j-i+1 > k){
            mpp[arr[i]]--;
            if(mpp[arr[i]] == 0) mpp.erase(arr[i]);
            i++;
        } 
        if(j-i+1 == k) cout << mpp.size() << " ";
        j++;
    }
    cout << endl;
    return 0;
}