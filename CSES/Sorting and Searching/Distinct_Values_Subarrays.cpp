#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> mpp;
    int i = 0;
    int j = 0;
    ll ans = 0;
    while(j < n){
        mpp[arr[j]]++;
        while(mpp[arr[j]] > 1){
            mpp[arr[i]]--;
            i++;
        }
        ans += j-i+1;
        j++;
    }
    cout << ans << endl;
    return 0;
}