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
        int x = arr[k-1];
        sort(arr.begin(), arr.end());
        int maxi = 0;
        for(int i=1; i<n; i++){
            if(arr[i] > x){
                maxi = max(maxi, arr[i]-arr[i-1]);
            }
        }
        if(maxi <= x){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}