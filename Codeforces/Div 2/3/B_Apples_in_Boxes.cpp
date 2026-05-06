#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll sum = 0;
        sort(arr.begin(), arr.end());
        for(auto it : arr){
            sum += (ll)it;
        }
        int mini = arr[0];
        int maxi = max(arr[n-1]-1, arr[n-2]);
        if(maxi-mini > k){
            cout << "Jerry" << endl;
            continue;
        }
        if(sum%2 == 0) cout << "Jerry" << endl;
        else cout << "Tom" << endl;
    }
    return 0;
}