#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int> mpp;
    for(int i=0; i<n; i++) cin >> arr[i];
    int i = 0;
    int j = 0;
    int maxi = 0;
    while(j < n){
        mpp[arr[j]]++;
        while(mpp[arr[j]] > 1 && i <= j){
            mpp[arr[i]]--;
            i++;
        }
        maxi = max(maxi, j-i+1);
        j++;
    }
    cout << maxi << endl;
    return 0;
}