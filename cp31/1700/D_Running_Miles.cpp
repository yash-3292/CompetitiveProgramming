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
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> pref(n);
        int val = INT_MIN;
        for(int i=0; i<n; i++){
            pref[i] = val;
            val = max(val, arr[i]+i);
        }
        vector<int> suf(n);
        val = INT_MIN;
        for(int i=n-1; i>=0; i--){
            suf[i] = val;
            val = max(val, arr[i]-i);
        }
        int maxi = 0;
        for(int i=1; i<n-1; i++){
            maxi = max(maxi, pref[i]+suf[i]+arr[i]);
        }
        cout << maxi << endl;
    }
    return 0;
}