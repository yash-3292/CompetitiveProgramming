#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;   
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> mpp;
    int i = 0;
    int j = 0;
    ll ans = 0;
    while(j < n){
        mpp[arr[j]]++;
        while(mpp.size() > k){
            mpp[arr[i]]--;
            if(mpp[arr[i]] == 0) mpp.erase(arr[i]); 
            i++;
        }
        ans += j-i+1;
        j++;
    }
    cout << ans << endl;
    return 0;
}